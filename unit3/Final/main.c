#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void clear(void);
void greet(void);
bool game(void);

// Variables que usaremos
string num;
int answ;
int lives;
int k;
int math;
int math2;
int math3;

int main(int argc, string argv[])
{
    if (argc != 4)
    {
        printf("Porfavor introduce tres numeros grandes separados");
        printf(" (./ main 312, 1024, 12), gracias.\n");
        return 1;
    }
    if (argc == 4)
    {
        string one = argv[1];
        string two = argv[2];
        string three = argv[3];
        
        for (int j = 0, k = strlen(one); j < k; j++)
        {
            // Si un char no es letra, termina el programa
            if (isalpha(one[j]))
            {
                printf("Se que solo soy una compu, pero porfa, dije numeros\n");
                return 2;
            }
        }
        for (int j = 0, k = strlen(two); j < k; j++)
        {
            // Si un char no es letra, termina el programa
            if (isalpha(two[j]))
            {
                printf("Se que solo soy una compu, pero porfa, dije numeros\n");
                return 3;
            }
        }
        for (int j = 0, k = strlen(three); j < k; j++)
        {
            // Si un char no es letra, termina el programa
            if (isalpha(three[j]))
            {
                printf("Se que solo soy una compu, pero porfa, dije numeros\n");
                return 4;
            }
        }
        
        math = atoi(argv[1]);
        math2 = atoi(argv[2]);
        math3 = atoi(argv[3]);
        
        greet();
        if (num[0] != 49)
        {
            printf("Te dije que 'presiona 1' tonto,"); 
            printf(" que no sabes leer? Ok, bye.\n");
            return 5;
        }
        while (true)
        {
            clear();c
            
            if (!game())
            {
                break;
            }
            printf("\nNo puedo creer que me destruirias, pero bueno.");
            printf(" Te odio...pero ganaste! Que listo me saliste haha\n");
            return 0;
        }
        printf("\nQue mal, mejor suerte para la proxima. GAME OVER.\n");
        return 6;
    }
}    

void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}
void greet(void)
{
    clear();
    printf("¡Bienvenido al Quiz Mas Facil del Mundo!\n");
    sleep(3);
    clear();
    printf("Si desea comenzar, presiona 1\n");
    num = GetString();
}
bool game(void)
{
    answ = 0;
    lives = 3;
    
    do
    {
        printf("1. Cual es la septima letra del abecedario?\n");
        printf("1 = h\n");
        printf("2 = g\n");
        printf("3 = m\n");
        printf("4 = a\n");
        printf("\n\t\t\t\t\t Lives: %i\n", lives);
        answ = GetInt();
        if (answ != 4)
        {
            lives = lives - 1;
            clear();
        }
    }    
    while ((answ != 4) && (lives > 0));
    
    clear();
    if (lives > 0)
    {
        do
        {
            printf("2. Cual respuesta es muy grande?\n");
            printf("1 = ∞\n");
            printf("2 = RESPUESTA\n");
            printf("3 = elefante\n");
            printf("4 = muy grande\n");
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            answ = GetInt();
            if (answ != 3)
            {
                lives = lives - 1;
                clear();
            }
        } 
        while ((answ != 3) && (lives > 0));
    }
    
    clear();
    if (lives > 0)
    {
        do
        {
            printf("3. Cuanta tierra hay en un hoyo de 3 x 3 x 5 cm3?\n");
            printf("1 = 11 cm3\n");
            printf("2 = 45 cm3\n");
            printf("3 = 0 cm3\n");
            printf("4 = 22.5 cm3\n");
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            answ = GetInt();
            if (answ != 3)
            {
                lives = lives - 1;
                clear();
            }
        } 
        while ((answ != 3) && (lives > 0));
    }
    
    clear();
    if (lives > 0)
    {
        int d = 5;
        int board[5][5];
        do
        {
            printf("4. Cuantas letras hay en la gradilla?\n");
            int spacenum = (d * d) - 1;
            for (int i = 0; i < d; i++)
            {
                for (int j = 0; j < d; j++)
                {
                    board[i][j] = spacenum;
                    spacenum = spacenum - 1;
                }
            }
            for (int i = 0; i < d; i++)
            {
                for (int j = 0; j < d; j++)
                {
                    if (board[i][j] < 10)
                    {
                        if (board[i][j] == 0)
                        {
                            printf(" O ");
                        }
                        else
                        {
                            printf(" %d ", board[i][j]);
                        }
                    }
                    else
                    {
                        printf(" B ");
                    }
                }
                printf("\n\n");
            }
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            answ = GetInt();
            if (answ != 10)
            {
                lives = lives - 1;
                clear();
            }
        } 
        while ((answ != 10) && (lives > 0));
    }
    
    clear();
    if (lives > 0)
    {
        do
        {
            printf("5. Antes de que el Monte Everest fuera descubierta,"); 
            printf("cual era la montana mas alta?\n");
            printf("1 = Monte Macalu\n");
            printf("2 = Monte Everest\n");
            printf("3 = Monte K2\n");
            printf("4 = Monte Kilimanjaro\n");
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            answ = GetInt();
            if (answ != 2)
            {
                lives = lives - 1;
                clear();
            }
        } 
        while ((answ != 2) && (lives > 0));
    }
    
    clear();
    if (lives > 0)
    {
        do
        {
            printf("6. Apurate! Escribe que hay al final del mundo!\n\n"); 
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            string answ = GetString();
            k = answ[0];
            if (answ[0] != 33)
            {
                lives = lives - 1;
                clear();
            }
        }
        while (k != 33 && lives > 0);
    }
    
    clear();
    if (lives > 0)
    {
        do
        {
            printf("7. Elige la opcion de Si para salir\n"); 
            printf("1 = Si\n");
            printf("2 = No\n");
            printf("3 = Salir\n");
            printf("4 = Cancelar\n");
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            answ = GetInt();
            if (answ == 3 || answ == 4)
            {
                lives = lives - 1;
                clear();
            }
            if (answ == 1)
            {
                printf("Como usted diga: \n\n");
                sleep(1);
                return false;
            }
        } 
        while ((answ != 2) && (lives > 0));
    }
    
    clear();
    if (lives > 0)
    {
        do
        {
            printf("8. Que letra viene despues de t?\n"); 
            printf("1 = c\n");
            printf("2 = o\n");
            printf("3 = l\n");
            printf("4 = s\n");
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            char answ = GetChar();
            k = answ;
            if (k != 117)
            {
                lives = lives - 1;
                clear();
            }
        } 
        while ((k != 117) && (lives > 0));
    }
    
    clear();
    if (lives > 0)
    {
        do
        {
            printf("9. Cuantas letras hay en russo?\n"); 
            printf("1 = 33\n");
            printf("2 = 4\n");
            printf("3 = lol ni idea\n");
            printf("4 = 5\n");
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            answ = GetInt();
            if (answ != 2)
            {
                lives = lives - 1;
                clear();
            }
        } 
        while ((answ != 2) && (lives > 0));
    }
    
    clear();
    if (lives > 0)
    {
        do
        {
            printf("10. Ayudale a la computadora a hacer lo siguiente con tus");
            printf(" numeros...\nQue es %i / %i + %i x 0?", math, math2, math3);
            printf("\n\t\t\t\t\t Lives: %i\n", lives);
            answ = GetInt();
            if (answ != (math / math2) + (math3 * 0))
            {
                lives = lives - 1;
                clear();
            }
        } 
        while ((answ != (math / math2) + (math3 * 0)) && (lives > 0));
    }

    clear();
    if (lives > 0)
    {
        printf("BONUS: Haz llegado al final felicidades!\n");
        printf("Pero ahora te toca hacer una desicion final...suerte\n");
        sleep(4);
        clear();
        printf("Usa tus vidas restantes para jugar 'El Quiz Mas Facil 2'");
        printf(": presiona 1\n");
        printf("\nDestruye 'El Quiz Mas Facil' por siempre: presiona 2\n");
        answ = GetInt();
        if (answ == 1)
        {
            printf("\nNo puedo creer que pensaste que habia segunda parte");
            printf("...tonto!\n");
            return false;
        }
        if (answ == 2)
        {
            return true;
        }
    }
    
    if (lives == 0)
    {
        return false;
    }
    return true;
}