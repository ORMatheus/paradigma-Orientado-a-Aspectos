# paradigma-Orientado-a-Aspectos
Desafio de Projeto: Desenvolvendo um Projeto com o Paradigma de Programação Orientado à Aspectos


Título do Projeto: Validação Transversal de Saldo em Sistema Bancário com Programação Orientada a Aspectos
1. Resumo (Abstract)
Este projeto explora a aplicação do paradigma de Programação Orientada a Aspectos (POA) para resolver problemas de interesses transversais (cross-cutting concerns) em um sistema bancário simulado. O objetivo principal é desacoplar a lógica de negócio (saque e depósito) da lógica de validação (verificação de saldo), promovendo um código mais limpo, modular e de fácil manutenção.

2. O Problema
Em sistemas orientados puramente a objetos, regras de validação que se aplicam a múltiplas classes (como verificar se há saldo suficiente antes de um saque) tendem a ser replicadas em cada subclasse (ContaCorrente, ContaPoupanca, ContaInvestimento). Isso gera:

Código Espalhado (Scattered Code): A mesma validação repetida em vários lugares.

Acoplamento Alto: A classe de negócio precisa "saber" detalhes de como validar ou logar erros.

Dificuldade de Manutenção: Se a regra de validação mudar, todas as classes precisam ser alteradas.

3. A Solução Proposta
A implementação utiliza C++ para o modelo de objetos e AspectC++ para a modelagem dos aspectos. A arquitetura foi dividida em duas camadas:

Núcleo (Core Concern - OO): Classes hierárquicas (Conta e suas derivadas) focadas exclusivamente na execução funcional. O método sacar() é implementado assumindo o "caminho feliz" (happy path), apenas subtraindo o valor.

Aspecto (Cross-cutting Concern - POA): Um módulo separado (VerificacaoSaldo.ah) que intercepta chamadas. Ele atua como um "guardião", verificando pré-condições antes de permitir que o núcleo execute sua função.

4. Detalhes Técnicos da Implementação
A solução utiliza os seguintes mecanismos do AspectC++:

Pointcut (execution): Define o padrão de interceptação para qualquer método sacar(double) em qualquer subclasse de Conta.

Advice (around): Envolve a execução do método original. Este é o componente crítico que decide se:

Aprova: Invoca tjp->proceed(), permitindo o saque.

Bloqueia: Interrompe o fluxo e gera um log de erro, garantindo que o saldo não fique negativo, sem a necessidade de try/catch ou if/else nas classes de conta.

Introspecção (tjp): Utilização do ponteiro This Join Point para acessar dinamicamente a instância do objeto alvo e seus argumentos em tempo de execução.

5. Tecnologias Utilizadas
Linguagem Base: C++ (Standard).

Extensão de Linguagem: AspectC++ (para suporte a POA).

Compilador: ac++ (AspectC++ Weaver) em conjunto com g++.

6. Conclusão
O projeto demonstra que a utilização de POA permite remover completamente a lógica de verificação defensiva de dentro das classes de domínio. O resultado é um sistema onde as classes de Conta são puras e focadas em fazer a transação, enquanto o Aspecto garante a integridade dos dados de forma transparente e reutilizável.
