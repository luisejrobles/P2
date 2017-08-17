void putchar (char dato);
void imprimeBinario (unsigned long numero);
unsigned long generaX( unsigned long x, int n);
unsigned long modificaX( unsigned long x, int direccion, int M );

unsigned long msb = 2147483648;
unsigned long lsb = 1;
unsigned long x = 4294967295;
int direccion = 1;
int i = 0;

int main(void)
{
  int n = 32;
  int m = 2;
  x = generaX(x,n);
  imprimeBinario(x);
  x = modificaX(x,direccion,m);
  while(1)
  {

  }
  return 0;
}

void putchar( char dato )
{
  asm mov dl,dato
  asm mov ah,2
  asm int 21h
}

void imprimeBinario (unsigned long numero)
{
  for(i = 0; i<32; i++)
  {
    if (numero&msb)
      putchar('1');
    else
      putchar('0');
    if (((i+1)%4) == 0)
      putchar(' ');
    numero<<=1;
  }
  putchar(10);
}

unsigned long generaX( unsigned long x, int n)
{
  int difX = 32-n;
  for(i = 0; i<difX; i++)
    x>>=1;
  return x;
}

unsigned long modificaX( unsigned long x, int direccion, int M )
{
  unsigned long mask = 0;
  int i = 0;
  for( i=0; i<M; i++ )
  {
    int estado = 1;
    int j = 0;
    if( direccion == 1 )
    {
      mask = lsb;
      for( j=0; j<32; j++ )
      {
        if( ((x&mask) != 0) && (estado == 1) )
        {
          x&=(~(mask));
          estado=0;
        }
        else
          if ( ((x&mask) != 0) && (estado == 0) )
            estado = 1;
        mask<<=1;
      }
      direccion=0;
    }
    else
      if( direccion == 0 )
      {
        mask = msb;
        for( j=0; j<32; j++ )
        {
          if( ((x&mask) != 0) && (estado == 1) )
          {
            x&=(~(mask));
            estado = 0;
          }
          else
            if( ((x&mask) != 0) && (estado == 0) )
              estado = 1;
          mask>>=1;
        }
        direccion = 1;
      }
      imprimeBinario(x);
  }
  return x;
}
