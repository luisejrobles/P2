

char int2bin(int numero, char * bin);
int invierteLSB(int iX, int iN);
int invierteMSB(int iX,int iN);
void cuentaUnos(const char * bin);
void muestraBin(const char * bin);

char getch( void );

int main(void)
{
	char cX[8 * sizeof(int)+1];
	int iM, iN; 
	int bandera = 0;
	int iX = 0;
	printf("Pract. no.2");
	printf("\nLuis E. Jimenez Robles");
	
	iN = 25;
	iM = 4;
	printf("\n\nN: %d", iN);
	printf("\nM: %d\n", iM);

	iX = mascaraX(iN,iX);

	int2bin(iX,cX);
	
	muestraBin(cX);
	printf("\n");
	
	printf("\n================================================================");
	while(iM > 0)
	{
		printf("\n\n");
		printf("\nM: %d", iM);
		if(bandera == 0)
		{
			printf("\n<-\niX antes: %d",iX);
			iX = invierteLSB(iX,iN);
			printf("\niX inv: %d", iX);
			printf("\n");
			int2bin(iX,cX);
			muestraBin(cX);
			bandera = 1;
		}else if(bandera == 1){
			printf("\n->\niX antes: %d",iX);
			iX = invierteMSB(iX,iN);
			printf("\niX inv: %d",iX);
			printf("\n");
			int2bin(iX,cX);
			muestraBin(cX);
			bandera = 0;
		}

		getch();
		iM--;
	}
}

int validaN(int iN)
{
	if(iN > 0 && iN < 32 )
	{
		return 1;
	}else
	{
		return 0;
	}
}

int validaM(int iM,int iN)
{
	if(iM < (iN/2) && iM > 0){
		return 1;	
	}else 
	{
		return 0;
	}
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
	static int size = 8 * sizeof(int);
	
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
	while (bin[i])  //no toma en cuenta el caracter nulo
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
	int mask = 1, bandera = 0;
	iN--;
	int iN2 = iN;
	
	printf("\n");
	while(iN2 > 0)
	{
		mask = mask*2;
		iN2--;
	}	
	while(iN >= 0)
	{
		if((iX & mask) > 0)
		{
			if(bandera == 0)
			{
				iX^= mask;
				bandera = 1;

			}else if(bandera == 1)
			{
				bandera = 0;
			}
		}
		mask = mask / 2;
		iN--;
	}		
	return iX;
}

