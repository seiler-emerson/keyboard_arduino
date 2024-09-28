# Music Keyboard DIY

Este projeto tem como objetivo transformar teclados musicais com a placa-mãe danificada em um controlador MIDI funcional, utilizando um Arduino Mega para capturar as interações com as teclas e enviar sinais MIDI para um computador ou dispositivo musical compatível. A ideia é aproveitar a mecânica e a estrutura de teclados condenados.
O projeto base utilizado para este projeto foi o projeto do Daniel Moura, que pode ser encontrado [aqui](https://github.com/oxesoft/keyboardscanner).

Com a utilização de um Arduino, conseguimos implementar controles MIDI adicionais, como pitch bend, modulação e controle de oitavas, além de faders, potenciômetros e botões para controlar diversos parâmetros em uma DAW (Digital Audio Workstation). Esta parte ainda será desenvolvida.

O conceito acima é totalmente funcional, entretanto para quem quiser ir além vamos construir um sintetizador completo, capaz de executar soudfonts e outros softwares em multiplas camadas, através do projeto [Zynthian](https://zynthian.org/), que utiliza o raspberry como base do projeto.


# Arquivos

- axiom_code_tabs: Arquivo principal para execução.
- config.h: Definições de pinos e constantes globais, além do mapeamento das teclas e inicio das configurações.
- input.h: Esse código lê o estado de várias teclas (ou entradas digitais) e um pedal em um loop, armazenando os resultados no array `signals`, e conta quantos ciclos de leitura acontecem por segundo se a depuração estiver habilitada.
- midi.h: Esse código envia um evento MIDI ajustando a **velocidade (velocity)** de uma nota com base no tempo de entrada, aplicando uma correção específica para teclas pretas e limitando os valores mínimo e máximo permitidos.
- states.h: Esse código atualiza o estado de várias teclas (incluindo pressões, sustentações e liberações) e envia eventos MIDI apropriados com base no sinal de entrada e no estado da tecla, levando em consideração o uso de pedal de sustentação.

Caso queira usar apenas a funcionalidade de controlador, basta configurar o arquivo config.h

## Mapeamento e Definição das Teclas

Uma matriz de teclado com sensibilidade possui entradas e saidas. No caso deste projeto utilizei um teclado axiom 61 pro onde possui uma matriz 11x12.
Cada tecla é composta por 3 contatos, um contato superior, um contato inferior e um contato comum central. Os contatos inferiores e superiores possuem diodos zener.
No arquivo config.h foram definidor 23 pinos, (PIN_Ax e PIN_Bx) utilizando os pinos de 22 a 43 do Arduino Mega.
Observando a matriz vemos que as teclas são divididas em grupos, que pode variar em cada teclado. Nesse teclado em questão os grupos são de 6 teclas, onde 1 fio é responsável por 6 teclas.
Na parte superior cada tecla tem 2 fios, e esses fios obviamente são ligados com outras teclas para a formação da matriz.
Agora o mapeamento se torna simples, no arquivo config.h procure output_pins e input_pins dentro do objeto defina os pins para cada fio que sai de cada tecla.
- As entradas (input_pins) são os fios que estão diretamente ligados aos diodos 
- As saidas são os fios que não estão conectados a um diodo.
- No código cada tecla tem que ser representada por 2 output_pins e 2 input_pins. Nesse contexto meu C0 ficou:
`byte output_pins[] =  {
PIN_B1, //C0
PIN_B1, //C0
}`
`byte input_pins[] =  {
PIN_A1, //C0
PIN_A2,`
- Caso os diodos da sua matriz estejam em outra configuração, talvez os inputs devam ser trocados pelos outputs e vice versa.

## Convertendo Arduino Mega em MIDI

Para converter o arduino mega em um dispositivo midi, utilizei da possibilidade de alteração do bootloader do chip 16u2.
ATENÇÃO apenas arduinos Mega/Uno com esse chip funcionarão com esse procedimento.
- Usando o Homebrew instalei o dfu-programer

    brew install dfu-programmer

- Então baixe o arquivo dualMoco.hex que é um firmware personalizado que faz o chip 16u2 ser reconhecido como midi. Pode ser encotrado neste projeto e também no [github dos desenvolvedores.](https://github.com/kuwatay/mocolufa/tree/master/HEX)
- É importante que no código as comunicações seriais estejam configuradas em 31250 para funcionarem.
- Conecte o arduino mega e feche um curto com um jumper rapidamente nos 2 primeiros pinos, logo em seguida remova o jumper.
 ![jumper mega](/assets/mega.png)
- Agora no terminal execute a limpeza do bootloader 
 `dfu-programmer atmega16u2 erase`
- Por fim instalei o dualMoco.hex
`dfu-programmer atmega16u2 flash /Users/emerson/Downloads/dualMoco.hex`
- Caso queira voltar ao boot original repita os passos anteriores mas faça o flesh do bootloader original do Mega/Uno.
`dfu-programmer atmega16u2 flash /Users/emerson/Downloads/Arduino-usbserial-mega.hex`
- Execute um reset e remova e insira o ubs.
`dfu-programmer atmega16u2 reset`
- Pronto agora o dispositivo será reconhecido como dispositivo MIDI.

## FUNCIONAMENTO

Para ver o projeto em execução acesse [meu canal no youtube](https://youtube.com/@emersonseiler?sub_confirmation=1)
