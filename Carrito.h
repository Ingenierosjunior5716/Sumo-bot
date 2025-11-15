class Carrito {
  private: //Se declaran los pines que utiliza el carrito asi como las velocidades (vel)
    int in1 = 4;
    int in2 = 5;
    int in3 = 6;
    int in4 = 7;
    int PWM12 = 3;
    int PWM34 = 9;
    int vel12 = 100;
    int vel34 = 100;

  public: //Se declaran los atributos (void setup) y metodos (funciones) de nuestra clase
    //Atributos
    Carrito() { 
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      pinMode(in3, OUTPUT);
      pinMode(in4, OUTPUT);
    }

    //Funciones
    void adelante() {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(PWM12, vel12);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(PWM34, vel34);
    }

    void izquierda() {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(PWM12, vel12);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(PWM34, vel34);
    }

    void derecha() {
      digitalWrite(in1,HIGH);
      digitalWrite(in2, LOW);
      analogWrite(PWM12, vel12);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(PWM34, vel34);
    }

    void atras() {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(PWM12, vel12);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(PWM34, vel34);
    }

    void parar() {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
};