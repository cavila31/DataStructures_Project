#ifndef CAJAMATRIZ_H
#define CAJAMATRIZ_H


class cajaMatriz
{
public:
    cajaMatriz();
    virtual ~cajaMatriz();
    void setPeso(int a);
    void setExiste(bool a);
    int getPeso();
    bool getExiste();
protected:
private:
    int peso;
    bool existe;
};

#endif // CAJAMATRIZ_H
