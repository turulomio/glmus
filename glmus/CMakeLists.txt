cmake_minimum_required(VERSION 2.8)
project(glMus)
add_definitions( -Wall )
find_package(Qt4 REQUIRED)
include( ${QT_USE_FILE} )

SET( MAIN_SRCS main.cpp )
SET( UI_SRCS ui/frmMain.cpp ui/wdgGame.cpp)
SET( CORE_SRCS core/sleeper.cpp core/setequipos.cpp core/juego.cpp core/vaca.cpp core/equipo.cpp core/setjugadores.cpp core/mem.cpp core/baraja.cpp core/carta.cpp core/jugador.cpp core/partida.cpp)
SET( UI_MOC_HDRS  ui/frmMain.h ui/wdgGame.h core/juego.h core/jugador.h)
SET( UIS ui/frmMain.ui ui/wdgGame.ui)
SET( RCS images/glmus.qrc )
SET( TRANSLATIONS i18n/glmus_en.ts)
QT4_ADD_RESOURCES( RCS_SRCS ${RCS} )
QT4_WRAP_UI( UI_HDRS ${UIS} )
QT4_WRAP_CPP( UI_MOC_SRCS ${UI_MOC_HDRS} )

#these are my source files in the project
SET(FILES_TO_TRANSLATE
   ${SRCS} 
   ${UI_MOC_HDRS}
   ${UIS}
   ${UI_SRCS}
 )
 
QT4_CREATE_TRANSLATION(QM_FILES ${FILES_TO_TRANSLATE} ${TRANSLATIONS})
QT4_ADD_TRANSLATION(QM ${TRANSLATIONS}) 

add_custom_target (translations_target DEPENDS ${QM_FILES})
 
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ui core)

#qt4_automoc(${glMus_SRCS})
add_library(glmuscore SHARED ${CORE_SRCS} ${RCS_SRCS})
set_property(TARGET glmuscore PROPERTY SOVERSION 1.0)
target_link_libraries(glmuscore ${SAMPLE_CORE_SRCS} ${QT_QTCORE_LIBRARY})

add_library(glmusui SHARED ${UIS} ${UI_MOC_SRCS} ${UI_SRCS}  ${RCS_SRCS} ${QM_FILES})
set_property(TARGET glmusui PROPERTY SOVERSION 1.0)
target_link_libraries(glmusui ${SAMPLE_UI_SRCS} ${SAMPLE_UI_MOC_HDRS} ${SAMPLE_RC_SRCS}  ${SAMPLE_UI_HDRS} ${QT_QTCORE_LIBRARY})


add_executable(glMus ${MAIN_SRCS})
target_link_libraries(glMus ${SAMPLE_CORE_SRCS} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} glmusui glmuscore)

install(TARGETS glmuscore LIBRARY DESTINATION lib)
install(TARGETS glmusui LIBRARY DESTINATION lib)
install(TARGETS glMus RUNTIME DESTINATION bin)
install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/project/)
