    
<h1 align="center">IC: Projeto 2</h1> 

## Compilar: 
Ir a `Projeto3/fcm-example-src` e fazer make


<br>

### Exercício 1
    
    ../fcm-example-bin/fcm_test <input_file> <k> <alpha>
    Exemplo:
    ../fcm-example-bin/fcm_test ./textos/dutch.txt 4 0.1

<br>


<br>

### Exercício 2
    
    
    ../fcm-example-bin/lang  <model_file> <k> <alpha> <text_file>
    Exemplo:
    ../fcm-example-bin/lang ./textos/dutch.txt 4 0.1 ./textos/pt.txt

<br>

### Exercício 3
    
    ../fcm-example-bin/findlang <model_file> <k> <alpha> [<textfile> ... <textfile>]
    Exemplo:
    ../fcm-example-bin/findlang textos/teste.txt 4 0.1 textos/dutch.txt textos/eng.txt textos/esp.txt textos/fin.txt textos/fr.txt textos/ger.txt                  textos/ita.txt textos/pol.txt textos/pt.txt textos/swe.txt

<br>

### Exercício 4
    
    ../fcm-example-bin/locatelang <model_file> <k> <alpha> <window_size> [<textfile> ... <textfile>]
    Exemplo:
    ../fcm-example-bin/locatelang textos/locatelang.txt 4 0.1 3000 textos/dutch.txt textos/eng.txt textos/esp.txt textos/fin.txt textos/fr.txt                    textos/ger.txt textos/ita.txt textos/pol.txt textos/pt.txt textos/swe.txt

<br>


