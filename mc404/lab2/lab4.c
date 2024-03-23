int read(int __fd, const void *__buf, int __n){
    int ret_val;
  __asm__ __volatile__(
    "mv a0, %1           # file descriptor\n"
    "mv a1, %2           # buffer \n"
    "mv a2, %3           # size \n"
    "li a7, 63           # syscall write code (63) \n"
    "ecall               # invoke syscall \n"
    "mv %0, a0           # move return value to ret_val\n"
    : "=r"(ret_val)  // Output list
    : "r"(__fd), "r"(__buf), "r"(__n)    // Input list
    : "a0", "a1", "a2", "a7"
  );
  return ret_val;
}

void write(int __fd, const void *__buf, int __n)
{
  __asm__ __volatile__(
    "mv a0, %0           # file descriptor\n"
    "mv a1, %1           # buffer \n"
    "mv a2, %2           # size \n"
    "li a7, 64           # syscall write (64) \n"
    "ecall"
    :   // Output list
    :"r"(__fd), "r"(__buf), "r"(__n)    // Input list
    : "a0", "a1", "a2", "a7"
  );
}

void exit(int code)
{
  __asm__ __volatile__(
    "mv a0, %0           # return code\n"
    "li a7, 93           # syscall exit (64) \n"
    "ecall"
    :   // Output list
    :"r"(code)    // Input list
    : "a0", "a7"
  );
}

void _start()
{
  int ret_code = main();
  exit(ret_code);
}

void copy_str(char *source, char *destiny, int bit_len) 
{
    for (int i=0; i<bit_len; i++){
        *(destiny+i) = *(source+i);
    }
}


char *hex_to_bin_single(char hex) {
    switch (hex) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': case 'a': return "1010";
        case 'B': case 'b': return "1011";
        case 'C': case 'c': return "1100";
        case 'D': case 'd': return "1101";
        case 'E': case 'e': return "1110";
        case 'F': case 'f': return "1111";
        default: return NULL;
    }
}

void hex_to_bin_full(char *source, char *destiny, int bit_len) {
    destiny[0]='0';
    destiny[1]='b';

    for (int i=2; i<bit_len; i++)
    {
        if (destiny=='\n'){
            break;
        }
        destiny[i] = hex_to_bin_single(source[i]);
    }
}

void hex_to_dec(char *source, char *destiny, int bit_len) 
{

}

#define STDIN_FD  0
#define STDOUT_FD 1
#define BIT_LEN 34

char in[BIT_LEN];
char decimal[BIT_LEN];
char out1[BIT_LEN];
char out2[BIT_LEN];
char out3[BIT_LEN];
char out4[BIT_LEN];
char out5[BIT_LEN];

int main()
{

/*
a entrada é em hexa por complemento de 2 quando começar com 0x, ou é decimal que pode ser negativo (com sinal '-').

tem que printar 5 saídas:
1. em binário, começando por 0b e em complemento de 2 se for negativo;
2. em decimal, com sinal, lendo da entrada como complemento de 2;
3. em decimal, lendo na entrada como sem assinatura e endianness trocado;
4. em hexa, começando por 0x e lendo da entrada como complemento de 2;
5. em octal, começando por 0o e lendo da entrada como complemento de 2;
*/

    // se vier hexa, ja ganha a 4. 
    // aí converte pra binario e faz a 1
    // depois converte pra octal e faz a 5.
    // por último, converte pra decimal e faz a 2 e 3

    // se vier decimal, ja ganha a 2 e a 3.
    // ai converte pra binario e faz a 1.
    // depois pega esse binario, salva e converte pra otal e faz a 5.
    // por ultimo pega o binário de novo e converte pra hexa e faz a 4.

    // metodo 2: certo - converter primeiro pra dec, depois ir fazendo o resto

    
    read(STDIN_FD, in, BIT_LEN);
    
    if (in[1]=='x') {
        //é em hexa

        copy_str(in, out4, BIT_LEN); //4 feito
        hex_to_dec(in, decimal, BIT_LEN);

        dec_to_bin(decimal, out1, BIT_LEN); //1 feito

        if (in[2]>'8'){
            //é negativo
            
            

            dec_to_format_out2()
            

        }
    }

    else {
        //é em decimal

        copy_str(in, out2, BIT_LEN);

        
    }

    //write(STDOUT_FD, out2, BIT_LEN);
    return 0;
}