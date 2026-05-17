#include <iostream>
#include <string>

using namespace std;

// Dados fixos de exemplo
string usuarios[5];
string senhas[5];
int totalUsuarios = 0;

void cadastrar() {
    if (totalUsuarios >= 5) {
        cout << "\nLimite de usuarios atingido!\n";
        return;
    }

    string usuario, senha;

    cout << "\n=== CADASTRO ===\n";

    cout << "Digite o nome de usuario: ";
    cin >> usuario;

    cout << "Digite a senha: ";
    cin >> senha;

    // Verifica se o usuario ja existe
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i] == usuario) {
            cout << "Usuario ja cadastrado!\n";
            return;
        }
    }

    usuarios[totalUsuarios] = usuario;
    senhas[totalUsuarios] = senha;

    totalUsuarios++;

    cout << "Cadastro realizado com sucesso!\n";
}

void login() {
    string usuario, senha;
    bool autenticado = false;

    cout << "\n=== LOGIN ===\n";

    cout << "Usuario: ";
    cin >> usuario;

    cout << "Senha: ";
    cin >> senha;

    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i] == usuario && senhas[i] == senha) {
            autenticado = true;
            break;
        }
    }

    if (autenticado) {
        cout << "Login realizado com sucesso!\n";
    } else {
        cout << "Usuario ou senha incorretos!\n";
    }
}

void listarUsuarios() {
    cout << "\n=== USUARIOS CADASTRADOS ===\n";

    if (totalUsuarios == 0) {
        cout << "Nenhum usuario cadastrado.\n";
        return;
    }

    for (int i = 0; i < totalUsuarios; i++) {
        cout << i + 1 << " - " << usuarios[i] << endl;
    }
}

int main() {
    int opcao;

    do {
        cout << "\n===== SISTEMA DE AUTENTICACAO =====\n";
        cout << "1 - Cadastrar usuario\n";
        cout << "2 - Fazer login\n";
        cout << "3 - Listar usuarios\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrar();
                break;

            case 2:
                login();
                break;

            case 3:
                listarUsuarios();
                break;

            case 0:
                cout << "Encerrando sistema...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}