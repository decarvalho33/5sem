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

void write(int __fd, const void *__buf, int __n){
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

void exit(int code){
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

#define STDIN_FD  0
#define STDOUT_FD 1
#define BYTE_LEN 6

char buffer[BYTE_LEN];
char out[2];

int main()
{
  /* Lê uma string da entrada padrão */
  int n = read(STDIN_FD, (void*) buffer, BYTE_LEN);

  int s1 = buffer[0]-'0';
  int s2 = buffer[4]-'0';

  int result;

  if(buffer[2] == '+') {
      result = s1+s2;
  }

  if(buffer[2] == '-') {
      result = s1-s2;
  }

  if(buffer[2] == '*') {
      result = s1*s2;
  }

  if (result == 0){
    out[0]='0';
  } else{
    out[0]=result+'0';
  }

  out[1] = '\n';

  write(STDOUT_FD, (void*) out, 4);

  return 0;
}
