    
<h1 align="center">IC: Projeto 1</h1> 

## Compilar: 
Ir a `proj1/sndfile-example-src` e fazer make

<br>

### Exercício 2

<br>

### Exercício 3

**Para reduzir 4 bits:**

    ../sndfile-example-bin/wav_quant ./Audio\ files\ -\ WAV\ format-20221010/sample01.wav 4 output.wav
Pode averiguar os dados obtidos ouvindo o ficheiro de audio gerado.
<br>



### Exercício 4

    ../sndfile-example-bin/wav_cmp ./Audio\ files\ -\ WAV\ format-20221010/sample01.wav output.wav

<br>

### Exercício 5

    ../sndfile-example-bin/wav_cmp <audio_file> <wanted_effect> <delay> <eco_attenuation>
    
    Existem dois tipos de efeitos, simples eco e múltiplos ecos
    Para simples ecos:
        ../sndfile-example-bin/wav_cmp ./Audio\ files\ -\ WAV\ format-20221010/sample01.wav simple_eco 5000 0.5
    Para múltiplos ecos:
        ../sndfile-example-bin/wav_cmp ./Audio\ files\ -\ WAV\ format-20221010/sample01.wav multiple_eco 5000 0.5
<br>

### Exercício 7
* **Encode:**

    ../sndfile-example-bin/encoder ./encoder.txt ./encoderout.txt
* **Decode:**

    ../sndfile-example-bin/decoder ./encoderout.txt ./decoderout.txt
   <br>

### Exercício 8


