# A05 - Sistema de Filtragem de Água

  O projeto de Filtragem de Água tem como objetivo principal implementar um sistema capaz de receber água de uma fonte externa, como a água da chuva coletada por meio de uma calha, e realizar um processo de verificação e ajuste do nível de pH dessa água. O resultado desse processo é a obtenção de uma água com pH equilibrado, pronta para ser utilizada em diversas aplicações, tais como a rega de plantas, o abastecimento de aquários ou o cultivo em mini-hortas, entre outros.
  
### Integrantes
- Luca Figliola Silvestri
- Pedro Henrique Costa dos Santos
- Victor Pereira de Sousa
  
## Componentes Físicos
  
- Placa ESP32: Plataforma programável eletrônica responsável por receber os dados coletados pelo medidor de pH e de nível da água e controlar as mini bombas.

- Sensor de pH: Controlado pelo ESP32, esse sensor é utilizado para medir o pH da água antes e depois do processo de correção. Ele fornece informações cruciais sobre a acidez da água.

- Sensor do nível de água: Também controlado pelo ESP32, esse sensor tem a função de medir o nível da água. Assim que o valor estipulado é alcançado, ele inicia o processo de controle.

- Mini-bombas: Normalmente utilizadas em aquários, as mini-bombas são responsáveis pelo bombeamento da água para o compartimento adequado no projeto.

- Motor Shield L293D: Uma placa de expansão para controlar motores DC usando o ESP32. Será utilizado para ligar as mini-bombas.

- Pedras Dolomita: As pedras dolomita, compostas principalmente por carbonato de cálcio e magnésio, possuem propriedades alcalinizantes. Sua função é elevar o pH da água da chuva, reduzindo sua acidez.

## Programação
  
Os sistemas do projeto foram desenvolvidos utilizando a linguagem C++ por meio da plataforma Arduino IDE. A programação abrange o controle completo de todas as funcionalidades da placa ESP32.

A escolha da linguagem C++ proporcionou um ambiente robusto e flexível para o desenvolvimento dos sistemas, permitindo a implementação de algoritmos complexos e a interação direta com os recursos da placa ESP32.

A plataforma Arduino IDE foi utilizada como a principal ferramenta de desenvolvimento, oferecendo uma interface intuitiva e amigável para escrever, compilar e carregar o código no ESP32. A programação desenvolvida abrange todas as funcionalidades e controles necessários para o projeto, incluindo a interação com sensores, atuadores e dispositivos externos.

Além disso, utilizamos a biblioteca Adafruit Motor Shield Library para facilitar o controle do Motor Shield L293D através do código.
