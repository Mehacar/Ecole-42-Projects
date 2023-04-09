1
/*
void    start_control(char **data, int y, int x) //y = 2, x  = 1
{
    if (data[y + 1][x] != '.' && data[y + 1][x] != '1')
    {
        y++;

        data[y][x] = '.';
        start_control(data, y, x);
        y--;
    }
}


int main() 
{
char **data;
int y=4; int x=6; int i;

data = (char**)malloc(y * sizeof(char*));
for (i = 0; i <y; i++)
{
    data[i] = (char*)malloc(x * sizeof(char));
}

strcpy(data[0], "11111");
strcpy(data[1], "10PC1");
strcpy(data[2], "100E1");
strcpy(data[3], "11111");

strcpy(data[0], "11111");
strcpy(data[1], "10PC1");
strcpy(data[2], "100E1");
strcpy(data[3], "11111");

int b = 2; int a = 1; 
  start_control(**data, b, a);

  return 0;
}
*/