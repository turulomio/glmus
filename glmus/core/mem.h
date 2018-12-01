#ifndef MEM_H
#define MEM_H



//Carga el fichero de configuración
class Mem
{
public:
    Mem();
    virtual ~Mem();
    void cargarMemoria();
    int vacapoints;//Tamaño de las vacas
    int numvacas;
    
};

#endif // MEM_H
