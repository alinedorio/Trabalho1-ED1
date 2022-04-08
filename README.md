# Trabalho1-ED1

# EDCare: ED Cuidando dos Idosos!

Devido ao aumento da expectativa de vida da população mundial e à queda nas taxas de natalidade,
a população mundial está envelhecendo. Em paralelo, com avanços na medicina e mudanças no
estilo de vida, espera-se que os idosos possam levar uma vida independente e com saúde! No
entanto, nem sempre isso é possível. Diante desta realidade, diversos sistemas de monitoramento
de idosos vêm sendo desenvolvidos. Imaginem o seguinte cenário:

Maria tem 88 anos, vive de forma independente mas, recentemente, tem sofrido com quedas. Sua
amiga Alice, de 80, também mora sozinha e no geral tem boa saúde. Elas conhecem o João, de 85,
que está apresentando episódios de febre e precisa de ajuda quando isso acontece. Juntos, os três e
outros amigos formam uma rede de apoio, ou seja, um ajuda o outro quando há necessidade. Para
ajudar no monitoramento, os idosos e seus familiares contrataram um sistema computacional que
se baseia em dados sensoriados que permitem detectar situações nas quais os idosos precisam de
ajuda. A ideia principal é que eles possam ajudar uns aos outros, sempre que for possível. No
entanto, quando a situação é mais grave, por exemplo, em caso de queda ou uma febre muito alta, o
sistema aciona um cuidador (familiar ou profissional). O idoso é equipado com três sensores: de
localização, temperatura e queda. O cuidador é equipado com sensor de localização.

Vamos implementar neste trabalho uma versão simplificada deste sistema! Vamos contemplar as
seguintes situações:
1) Quando o idoso tiver uma queda e/ou febre alta (acima de 38): sistema deve acionar o
cuidador que estiver mais próximo ao idoso;
2) Quando o idoso tiver febre baixa (entre 37 e 38): sistema deve acionar o amigo que estiver
mais próximo ao idoso;
3) Quando o idoso tiver 4 ou mais episódios de febre baixa (sem febre alta “no meio”): sistema
deve acionar o cuidador que estiver mais próximo ao idoso;
Configuração Inicial

Em EDCare é possível modelar uma rede de amigos de apoio. Para modelar essa rede de apoio,
vamos utilizar uma lista de listas, como na Figura 1. Vemos as seguintes relações nessa figura: João
tem dois amigos, Maria e Pedro (a amizade é recíproca, ou seja, Maria e Pedro também são amigos
de João); Pedro e Alice também são amigos.

Essa rede apoio especifica as relações de amizades que poderão ser acionadas nos casos de situação
de febre baixa.

Além de uma lista de amigos, as pessoas devem ter uma lista de cuidadores; As ações tomadas pelo
sistema (acionamento de cuidadores e amigos) devem ser mantidas em históricos. Usem estruturas
encadeadas de forma eficiente, como ilustrado na figura 1.

- Entradas do Sistema:
O arquivo de entrada a seguir define a rede de apoio (apoio.txt). A primeira linha contém os nomes
de todas as pessoas da EDCare. A seguir, as amizades são definidas, linha a linha:

Joao;Maria;Pedro;Alice
Joao;Maria
Joao;Pedro
Pedro;Alice

O arquivo de entrada a seguir define os cuidadores por idoso (cuidadores.txt). A primeira linha
contém os nomes de todos os cuidadores EDCare. As linhas seguintes informam:

idoso;cuidador1;cuidador2;etc (este idoso pode ser ajudado pelos cuidadores que seguem na
mesma linha).

Cuidador1;Cuidador2;Cuidador3;Cuidador4
Joao;Cuidador1;Cuidador4
Maria;Cuidador2;Cuidador3;Cuidador1
Alice;Cuidador1;Cuidador2
Pedro;Cuidador4;Cuidador3

O arquivo de entrada a seguir simula as leituras dos sensores de cada uma das pessoas do sistema.
Em um sistema real, teríamos os dados sensoriados em tempo-real. Porém, na nossa versão
simplificada, as leituras dos sensores são fornecidas em batches, em arquivos. Cada arquivos contém
um conjunto de leituras de temperatura, latitude, longitude e se houve queda (0 ou 1), no seguinte
formato: temp;lat;long;queda. Cada linha do arquivo representa uma leitura destes sensores, da
mais antiga para a mais recente.

O arquivo a seguir, por exemplo, representa as informações sensoriadas de João. A primeira linha
apresenta as medidas mais antigas: inicialmente, sua temperatura estava a 36 graus. Lat:long 3345:
54572 e não foi detectada uma queda (0). João passou por alguns episódios notórios: na segunda
medida, ele estava com febre alta. Em seguida, teve febre baixa nas medidas 4, 6, 7 e 9. Na última
medida, foi detectada uma queda. Ações devem ser tomadas diante dessas situações, como descrito
anteriormente. O nome do arquivo é o próprio nome do usuário (Joao.txt).

36.0;3345;54572;0
38.5;3347;54577;0
36.4;3345;54578;0
37.5;3347;54579;0
36.0;3348;54580;0
37.5;3347;54570;0
37.8;3340;54572;0
36.0;3341;54571;0
37.9;3343;54573;0
36.0;3345;54570;1

O arquivo de entrada a seguir contém as medidas de localização (lat;long) do Cuidador1, por
exemplo. O nome do arquivo é o próprio nome do cuidador (Cuidador1.txt).

3345;54572
3347;54560
3340;54561
3341;54562
3342;54563
3346;54564
3343;54598
3330;54577
3320;54572
3315;54572

O arquivo a seguir informa as leituras de sensores do Cuidador 4 (Cuidador4.txt):

5556;67432
5556;67432
5556;67432
5556;67432
5556;67432
5556;67432
5556;67432
5556;67432
5556;67432
5556;67432

O número de medidas (linhas dos arquivos) é o mesmo para todos os arquivos de idosos e
cuidadores.

Infelizmente, alguns idosos acabam falecendo e isso precisa ser tratado pelo sistema. O falecimento
de um idoso é reconhecido pela palavra “falecimento” no arquivo de entrada de dados sensoriados.
Por exemplo, o arquivo a seguir (Alice.txt) informa ao sistema do falecimento de Alice após a 3a
leitura de dados.

36.0;3345;54572;0
39.0;3347;54577;0
36.4;3345;54578;1
falecimento

Ao detectar o falecimento do idoso, o sistema deve atualizar as estruturas de dados para que a rede
de apoio reflita essa realidade.

Resumindo, para esse conjunto particular de idosos e cuidadores, teremos 10 arquivos de entrada, a
saber: apoio.txt, cuidadores.txt, Joao.txt, Alice.txt, Maria.txt, Pedro.txt, Cuidador1.txt, Cuidador2.txt,
Cuidador3.txt, Cuidador4.txt. Esta seria uma instância particular de EDCare. Poderemos ter várias
instâncias, como diferentes configurações de idosos e cuidadores.

- Saídas do Sistema:
As saídas do sistema são arquivos que descrevem as ações diante das medidas sensoriadas, por
idoso. Se há, por exemplo, 10 medidas sensoriadas, como no caso do arquivo de João, espera-se 10
saídas no arquivo. Abaixo está o arquivo de saída de João (Joao-saida.txt), considerando que o
Cuidador 1 estava mais perto e que Maria era também a amiga mais próxima (em todos os
momentos que foi necessário acioná-los):

tudo ok
febre alta, acionou Cuidador1
tudo ok
febre baixa, acionou amigo Maria
tudo ok
febre baixa, acionou amigo Maria
febre baixa, acionou amigo Maria
tudo ok
febre baixa pela quarta vez, acionou Cuidador1
queda, acionou Cuidador1

Considerando o arquivo de entrada com as informações de Alice (Alice.txt), vemos que ela faleceu
depois da 3a medida. Portanto, o arquivo de saída dela (Alice-saida.txt) deve ser:

tudo ok
febre alta, acionou Cuidador2
queda, acionou Cuidador2
falecimento

Resumindo, considerando os arquivos de entrada mencionados anteriormente, teremos 4 arquivos
de saída, a saber: Joao-saida.txt, Alice-saida.txt, Maria-saida.txt e Pedro-saida.txt.

- Execução do Sistema:
Podemos definir a execução do sistema em ciclos, da seguinte forma:
Enquanto houver informações de leituras de sensores a serem lidas nos
batches:
1) Leia medidas de sensores de idosos e cuidadores (apenas uma linha de
cada arquivo);
2) Atualize as estruturas de dados com os valores dos atributos
sensoriados;
3) Processa essas informações (verificar situações notórias, calcular
distâncias, registrar as informações históricas);
4) Escreve saídas;

- Regras Importantes
• Se houver queda e febre no mesmo conjunto de medidas: acionamento de queda prevalece;
• Depois de um acionamento de 4 episódios de febre baixa, deve-se começar a monitorar essa
situação do início, novamente. Por exemplo, depois da 9a leitura de João (que acionou essa
situação), se houver febre baixa novamente, aciona-se um amigo, como de costume;
• O cálculo da distância em situações reais deve considerar a curvatura da terra. Aqui nós
vamos simplificar as coisas (ufa!). Utiliza a distância euclidiana para calcular a distância
entre as pessoas.
• Usar listas encadeadas para implementar a EDCare;
• Estruture/modularize a EDCare usando as técnicas de TAD ensinados em sala de aula;
• Mantenham as mensagens de saída seguindo o padrão descrito aqui nessa especificação
(testes serão automatizados);
• Para facilitar, assuma que os nomes são únicos e estão sempre consistentes entre os
arquivos.
