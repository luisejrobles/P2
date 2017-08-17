char int2bin(int numero, char * bin);
int invierteLSB(int iX, int iN);
int invierteMSB(int iX,int iN);
void cuentaUnos(const char * bin);
void muestraBin(const char * bin);
void putchar ( char dato );
void puts(char *str);

char enBin[]="\rBinario:\r\n";
char enter[]="\n\r";
char mLSB[]="\r\nLSB:\n\r";
char mMSB[]="\r\nMSB:\n\r";
char test[]="\n\r ENTRA\n\r";

int main(void)
{
	char cX[16 * sizeof(int)+1];
	int iM, iN; 
	int bandera = 0;
	int iX = 0;

		iN = 12;
		iM = 3;
		iX = mascaraX(iN,iX);
		puts(enBin);
		int2bin(iX,cX);
		puts(cX);
		puts(enter);
		
		while(iM > 0)
		{	
			if(bandera == 0)
			{
				iX = invierteLSB(iX,iN);
				puts(mLSB);
				int2bin(iX,cX);
				muestraBin(cX);
				bandera = 1;
			}else if(bandera == 1){
				iX = invierteMSB(iX,iN);
				puts(mMSB);
				int2bin(iX,cX);
				muestraBin(cX);
				bandera = 0;
			}
			iM--;
		}
	while(1)
	{
	}
	return 0;
}

int mascaraX(int iN,int iX)
{
	int mask = 0;
	int bitVal = 1;
	
	while(iN-- > 0)
	{
		
		mask|=bitVal;
		bitVal<<=1;
	}
	iX|= mask;
	
	return iX;
}

char int2bin(int numero, char * bin)
{
	int i, cont = 0;
	static int size = 16 * sizeof(int);
	
	for (i = size - 1; i >= 0; i--, numero >>= 1)
	{
		bin[i] = (01 & numero) + '0';
		bin[size] = '\0';
		cont++;
	}
	return *bin;
}

void muestraBin(const char * bin)
{	
	int i = 0;
	while (bin[i]) 
	{
		putchar(bin[i]);
		if(++i % 4 == 0 && bin[i])
		putchar(' ');
	}
}

int invierteLSB(int iX, int iN)
{	
	int mask = 1, bandera = 0; 
	while(iN > 0)
	{
		if((iX&mask) > 0)
		{
			if(bandera == 0)
			{
				iX ^= mask;
				bandera = 1;
			}else if( bandera == 1)
			{
				bandera = 0;
			}
		}
		mask = mask * 2;
		iN--;
	}
	
	return iX;
}

int invierteMSB(int iX,int iN)
{
	int mask = 1, bandera = 0, iN2 = 0;
	iN--;
	iN2 = iN;
	while(iN2 > 0)
	{
		mask = mask*2;
		iN2--;
	}
	
	while(iN >= 0)
	{
		if( (iX&mask) > 0)
		{
			if(bandera == 0)
			{
				iX ^= mask;
				bandera = 1;
			}else if(bandera == 1)
			{
				bandera = 0;
			}
		}
		mask = (mask/2);
		iN--;
	}
	return iX;
}

void puts(char *str)
{
	int count = 0; 
	char dato = ' ';
	while(*str)
	{
		putchar(*str++);
		count++;
		if(count == 4)
		{
			putchar(dato);
			count  = 0;
		}
	}
}

void putchar ( char dato )
{
	asm mov dl,dato
	asm mov ah,2
	asm int 21h
}
