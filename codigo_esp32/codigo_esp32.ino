#include <AFMotor.h>

int sensorNivelAgua = A0;
int sensorPh = A1;

AF_DCMotor bombaFiltro(1); // Bomba responsável por liberar a água com pH desequilibrado no filtro de pedras
AF_DCMotor bombaFinal(2); // Bomba responsável por liberar a água com pH equilibrado para fora do sistema
AF_DCMotor bombaRetorno(3); // Bomba responsável por liberar a água do compartimento de filtragem de volta para o compartimento de medição do pH

void setup()
{
  pinMode(sensorNivelAgua, INPUT);
  pinMode(sensorPh, INPUT);
  Serial.begin(9600);
}

// Função para medir o pH da água
float medirPh()
{
  // Medida inicial gerada pelo sensor de pH
  int medidaInicial = analogRead(sensorPh);
  Serial.print("Medida: ");
  Serial.print(medidaInicial);

  // Medida da voltagem gerada pelo sensor de pH
  double voltagem = 5.0 / 1024.0 * medidaInicial;
  Serial.print("\n\nVoltagem: ");
  Serial.print(voltagem, 3);

  // Medida convertida para retornar a quantidade de pH de fato
  float medidaPh = 7 + ((2.5 - voltagem) / 0.18);
  Serial.print("\n\npH: ");
  Serial.print(medidaPh, 3);

  return medidaPh;
}

// Libera a água com pH desequilibrado no filtro de pedras
void ligarBombaFiltro()
{
  int tempoDeEspera = 0; // Variável que define o tempo que a bomba permanecerá acionada, precisamos fazer testes com a bomba para saber o tempo necessário para esvaziar o compartimento de água por completo
  int tempoDeEsperaFiltragem = 0; // Variável que define o tempo que o sistema esperará para retornar a água filtrada para o primeiro compartimento, precisamos fazer testes com o filtro para saber o tempo necessário para aguardar toda a água passar pela filtragem

  bombaFiltro.setSpeed(255);
  bombaFiltro.run(FORWARD);
  delay(tempoDeEspera);
  bombaFiltro.run(RELEASE);
  delay(tempoDeEsperaFiltragem);
  ligarBombaRetorno();
}

// Liberar a água do compartimento de filtragem de volta para o compartimento de medição do pH
void ligarBombaRetorno()
{
  int tempoDeEsperaRetorno = 0; // Variável que define o tempo que a bomba permanecerá acionada, precisamos fazer testes com a bomba para saber o tempo necessário para retornar toda a água para o início

  bombaRetorno.setSpeed(255);
  bombaRetorno.run(FORWARD);
  delay(tempoDeEsperaRetorno);
  bombaRetorno.run(RELEASE);
  // Aqui o sistema volta ao estágio inicial e continuará o loop, passando novamente pela verificação de pH
}

// Liberar a água com pH equilibrado para fora do sistema
void ligarBombaFinal()
{
  int tempoDeEsperaFinal = 0; // Variável que define o tempo que a bomba permanecerá acionada, precisamos fazer testes com a bomba para saber o tempo necessário para liberar toda a água para fora do sistema

  bombaFinal.setSpeed(255);
  bombaFinal.run(FORWARD);
  delay(tempoDeEsperaFinal);
  bombaFinal.run(RELEASE);
  // Aqui o sistema termina, liberando toda a água com o pH regulado
}

void loop()
{
  int nivelAgua = analogRead(sensorNivelAgua);
  
  // Se o tanque estiver cheio, fazer o que está no if
  if(nivelAgua >= 600)
  {
    int phAgua = medirPh();

    // Se o pH estiver desequilibrado, fazer o que está no if
    if(phAgua < 6.5 || phAgua >= 8)
    {
      ligarBombaFiltro();
    }
    // Se o pH estiver equilibrado, fazer o que está no else
    else
    {
      ligarBombaFinal();
    }
  }

  // Se o tanque não estiver cheio, repetir o loop
}