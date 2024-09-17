#include <iostream>
using namespace std;

void menu() {
  cout << "Bienvenido al cajero UPN \n";
  cout << "Seleccionar una de las siguientes opciones: \n";
  cout << "1. Retirar dinero " << endl;
  cout << "2. Consignar " << endl;
  cout << "3. Transferir a otra cuenta bancaria" << endl;
  cout << "4. Consultar saldo " << endl;
  cout << "5. Salir " << endl;
}

int main() {
  // Se declaran las variables
  int user = 123456789;
  int pass = 123;
  int cuenta_transferencia = 987654321;

  // Variables que se reciben
  int user_id;
  int password;
  int saldo = 0; // Supongamos que empieza con un saldo de 0
  int opcion;
  int monto_consignado;
  int transferencia;
  int retiro;

  cout << "Ingresa tu numero de documento: ";
  cin >> user_id;
  while(true) {
    cout << "Ingresa tu contraseña: ";
  cin >> password; 
    if (password == pass) {
      cout<<"Ingresaste con exito a tu cuenta"<<endl;
      break;
    } else {
      cout<<"Has colocado algo erroneo.Vuelve a intentar"<<endl;
    }
  }
 

  if (user_id == user && password == pass) {
    do {
      menu();
      cin >> opcion;

      switch (opcion) {
        case 1: // Opción para retirar dinero
          cout << "Ingresa el monto a retirar: ";
          cin >> retiro;
          if (retiro > saldo) {
            cout << "Tu saldo es insuficiente. Vuelve a intentarlo." << endl;
          } else {
            saldo -= retiro; // Se resta el retiro del saldo
            cout << "La operación se realizó con éxito. Tu saldo actual es: " << saldo << endl;
          }
          break;

        case 2: // Opción para consignar
          cout << "Este es tu saldo actual: " << saldo << endl;
          cout << "Ingresa el monto a consignar: ";
          cin >> monto_consignado;
          // Se suma el monto agregado al saldo
          saldo += monto_consignado;
          cout << "Monto ingresado con éxito!! \n";
          cout << "Tu saldo actual es: " << saldo << endl;
          break;

        case 3: // Opción para transferir a otra cuenta bancaria
          cout << "Ingresa el número de cuenta a transferir: ";
          cin >> cuenta_transferencia;
          if (cuenta_transferencia) {
            cout << "Ingresa el monto a transferir: ";
            cin >> transferencia;
            if (transferencia > saldo) {
              cout << "Tu saldo es insuficiente. Vuelve a intentarlo." << endl;
            } else {
              saldo -= transferencia; // Se resta la transferencia del saldo
              cout << "Transferencia exitosa!! Tu saldo actual es: " << saldo << endl;
            }
          } else {
            cout << "La cuenta bancaria no existe." << endl;
          }
          break;

        case 4: // Opción para consultar dinero en la cuenta
          cout << "Este es tu saldo actual: " << saldo << endl;
          break;

        case 5: // Opción para salir
          cout << "Gracias por utilizar nuestros servicios." << endl;
          break;

        default:
          cout << "Opción no válida. Inténtalo nuevamente." << endl;
      }
      cout << endl;
    } while (opcion != 5);

  } else {
    cout << "Usuario o contraseña incorrectos." << endl;
  }

  return 0;
}
