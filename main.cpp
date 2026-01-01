#include <iostream>
#include <string>
using namespace std;


class Conta{
    protected:
        double saldo;
        string titular;

    public:
        Conta(string nome, double saldoInicial):titular(nome),saldo(saldoInicial){}

        double getSaldo() const {return saldo;}
        string getTitular() const { return titular;}

        //metodo para permitir o polimorfismo
        //logica funcional para retirar dinheiro 
        virtual void sacar(double valor){
            saldo=saldo-valor;
            cout << "[OO] Saque de R$ " << valor << " efetuado na conta de " << titular << endl;
            cout << "[OO] Novo saldo: R$ " << saldo << endl;
        }
     
};

//subclasses

class ContaCorrente : public Conta{
    public:
        ContaCorrente(string nome,double saldo) : Conta(nome,saldo){}  
};


class ContaPoupanca : public Conta{
    public:
        ContaPoupanca(string nome ,double saldo) : Conta(nome,saldo){}
};

class ContaInvestimento : public Conta{
    public:
        ContaInvestimento(string nome,double saldo) : Conta(nome,saldo){}

};

int main(){
    ContaCorrente cc("Matheus ", 1000.00);
    ContaPoupanca contaP("Matheus", 500.00);

    cout << "Tentativa de saque valido:" << endl;
    cc.sacar(200);

    cout << "Tentativa de saque invalido:"<< endl;
    contaP.sacar(700.00);

    return 0;
}