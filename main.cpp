#include <iostream>
#include "no.h"
#include "binarytree.h"

using namespace std;


int main() {
    BinaryTree tree;
    int opcao, valor;

    do {
        cout << "\n===== MENU ARVORE BINARIA =====\n";
        cout << "1. Inserir elemento\n";
        cout << "2. Remover elemento\n";
        cout << "3. Imprimir arvore\n";
        cout << "4. Contar nos\n";
        cout << "5. Contar folhas\n";
        cout << "6. Mostrar altura\n";
        cout << "7. Mostrar menor valor\n";
        cout << "8. Mostrar maior valor\n";
        cout << "9. Percorrer em ordem (in-order)\n";
        cout << "10. Percorrer em pre-ordem\n";
        cout << "11. Percorrer em pos-ordem\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            tree.inserir(valor);
            break;
        case 2:
            cout << "Digite o valor a ser removido: ";
            cin >> valor;
            tree.remove(valor);
            break;
        case 3:
            cout << "\nArvore:\n";
            tree.print(tree.getRoot());
            break;
        case 4:
            cout << "Numero de nos: " << tree.countNodes() << endl;
            break;
        case 5:
            cout << "Numero de folhas: " << tree.countLeaves() << endl;
            break;
        case 6:
            cout << "Altura da arvore: " << tree.height() << endl;
            break;
        case 7:
            if (!tree.isEmpty())
                cout << "Menor valor: " << tree.getMinValue()->value << endl;
            else
                cout << "Arvore vazia.\n";
            break;
        case 8:
            if (!tree.isEmpty())
                cout << "Maior valor: " << tree.getMaxValue()->value << endl;
            else
                cout << "Arvore vazia.\n";
            break;
        case 9:
            cout << "Percorrendo em ordem: ";
            tree.printInOrder();
            cout << endl;
            break;
        case 10:
            cout << "Percorrendo em pre-ordem: ";
            tree.printPreOrder();
            cout << endl;
            break;
        case 11:
            cout << "Percorrendo em pos-ordem: ";
            tree.printPostOrder();
            cout << endl;
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
