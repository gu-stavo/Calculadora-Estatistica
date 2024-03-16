#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menu();
float calcularMedia(int n);
float calcularMediana();
int calcularModa();
float calcularVariancia(int qtdNumeros);
float calcularDesvioPadrao(int qtdNumeros);
float calcularEscoreZ(float valor, float media, float desvioPadrao);
float calcularErroMedia();
float calcularErroProporcao(float proporcao2);
float calcularProporcao();
float calcularTamanhoMedia();
float calcularTamanhoProporcao();


int main()
{

    int opcao, tamanho, qtdNumeros, erroTamanho, opcaoProporcao;
    float media, mediana, moda, variancia, desvioPadrao, escoreZ, valor;
    float intervaloConfianca1, intervaloConfianca2, mediaInter, valorErro, ValorErro, proporcao, proporcao2, intervaloConfiancaP1, intervaloConfiancaP2;
    float TamanhoMedia, TamanhoProporcao;
    int sucesso, Tproprocao;
    
    
    do
    {

        opcao = menu();

        switch (opcao)
        {
        case 1:
        {
            printf("Opcao selecionada: Media\n");
            printf("Quantos numeros deseja calcular a media? ");
            scanf("%d", &tamanho);
            media = calcularMedia(tamanho);
            printf("A media dos %d numeros e: %.2f\n", tamanho, media);
            break;
        }
        case 2:
        {
            printf("Opcao selecionada: Mediana\n");
            printf("Quantos numeros deseja calcular a media? ");
            scanf("%d", &tamanho);
            mediana = calcularMediana(tamanho);
            printf("A mediana dos numeros e: %.2f\n", mediana);
            break;
        }
        case 3:
        {
            printf("Opcao selecionada: Moda\n");
            printf("Quantos numeros deseja calcular a moda? ");
            scanf("%d", &tamanho);
            moda = calcularModa(tamanho);
            printf("A moda dos numeros e: %.f\n", moda);
            break;
        }
        case 4:
        {
            printf("Opcao selecionada: Variancia\n");
            printf("Quantos numeros deseja calcular a variancia? ");
            scanf("%d", &qtdNumeros);
            variancia = calcularVariancia(qtdNumeros);
            printf("A variancia dos numeros e: %.2f \n", variancia);
            break;
        }
        case 5:
        {
            printf("Opcao selecionada: Desvio Padrao\n");
            printf("Quantos numeros deseja calcular o desvio padrao? ");
            scanf("%d", &qtdNumeros);
            desvioPadrao = calcularDesvioPadrao(qtdNumeros);
            printf("O desvio padrao dos numeros e: %.2f\n", desvioPadrao);
            break;
        }
        case 6:
        {
            printf("Opcao selecionada: Escore Z\n");
            printf("Digite o valor: ");
            scanf("%f", &valor);
            printf("Digite a media: ");
            scanf("%f", &media);
            printf("Digite o desvio padrão: ");
            scanf("%f", &desvioPadrao);
            escoreZ = calcularEscoreZ(valor, media, desvioPadrao);
            printf("O Escore Z do numero e: %.2f\n", escoreZ);
            break;
        }
        case 7:
        {
            printf("Opcao selecionada: Intervalo de Confianca\n");
            printf("1. Intervalo de confianca para media\n");
            printf("2. Intervalo de confianca para proporcao\n");
            printf("Opcao: ");
            scanf("%d", &opcao);
            if (opcao == 1) {
                printf("Escolhido Intervalo de confianca para media \n");
                valorErro = calcularErroMedia();
                printf("Digite a media: \n");
                scanf("%f", &mediaInter);
                intervaloConfianca1 = mediaInter - valorErro;
                intervaloConfianca2 =mediaInter + valorErro;
                printf("O intervalo de confianca para media e: (%.2f ; %.2f)\n", intervaloConfianca1, intervaloConfianca2);

            } else if (opcao == 2) {
                printf("Escolhido - Intervalo de confianca para proporcao\n");
                printf("Voce tem um valor para a proporcao definido? (1 - Sim, 2 - Nao): ");
                scanf("%d", &opcaoProporcao);
                if(opcaoProporcao == 1){
                    printf("Digite o valor da proporcao: \n");
                    scanf("%f", &proporcao);
                    ValorErro = calcularErroProporcao(proporcao);
                    intervaloConfiancaP1 = proporcao - ValorErro;
                    intervaloConfiancaP2 = proporcao + ValorErro;
                    printf("O intervalo de confianca para media e: (%.2f ; %.2f)\n", intervaloConfiancaP1, intervaloConfiancaP2);
                }else if(opcaoProporcao == 2){
                    printf("Opcao escolhida: Nao ha valor, entao vamos calcular!\n");
                    proporcao2 = calcularProporcao();
                    printf("O valor da proporcao e: %2f\n", proporcao2);
                    ValorErro = calcularErroProporcao(proporcao2);
                    intervaloConfiancaP1 = proporcao2 - ValorErro;
                    intervaloConfiancaP2 = proporcao2 + ValorErro;
                    printf("O intervalo de confianca para media e: (%.2f ; %.2f)\n", intervaloConfiancaP1, intervaloConfiancaP2);
                }else{
                    printf("Opcao invalida.\n");
                    return 0;
                }

            }else{
                printf("Opcao invalida.\n");
                return 0;
            }
            break;
        }
        case 8:
        {
            printf("Opcao selecionada: Tamanho da Amostra\n");
            printf("O Erro Amostral e de Media ou de Proporcao (1 - Sim, 2 - Nao): ");
            scanf("%d", &erroTamanho);
            if(erroTamanho == 1){
                printf("Escolhido - Erro Amostral da Media \n");
                TamanhoMedia = calcularTamanhoMedia();
                printf("O tamanho da amostra e: %d \n",TamanhoMedia);
            }else if(erroTamanho == 2){
                printf("Escolhido - Erro Amostral de Proporcao \n");
                TamanhoProporcao = calcularTamanhoProporcao();
                printf("O tamanho da amostra e: %d \n",TamanhoProporcao);
            }else{
                printf("Opcao invalida!\n");
                break;
            }
        }
        case 0:
        {
            printf("Saindo do programa...\n");
            break;
        }
        default:
        {
            printf("Opcao invalida!\n");
            break;
        }
        }
    } while (opcao != 0);

    return 0;
}

int menu()
{
    int opcao;

    printf(" ══════════════════════════════ \n");
    printf("║           M E N U            ║\n");
    printf("╠══════════════════════════════╣\n");
    printf("║   1. Media                   ║\n");
    printf("║   2. Mediana                 ║\n");
    printf("║   3. Moda                    ║\n");
    printf("║   4. Variancia               ║\n");
    printf("║   5. Desvio Padrao           ║\n");
    printf("║   6. Escore Z                ║\n");
    printf("║   7. Intervalo de Confianca  ║\n");
    printf("║   8. Tamanho da Amostra      ║\n");
    printf("║   0. Sair                    ║\n");
    printf("╚══════════════════════════════╝\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

float calcularMedia(int tamanho)
{

    int i;
    float num, soma = 0.0, media;

    printf("Digite os %d numeros:\n", tamanho);

    for (i = 0; i < tamanho; i++)
    {
        scanf("%f", &num);
        soma += num;
    }

    media = soma / tamanho;

    return media;
}

int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

float calcularMediana(int tamanho)
{
    int i;
    int numeros[tamanho];

    printf("Digite os %d numeros:\n", tamanho);
    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", &numeros[i]);
    }

    qsort(numeros, tamanho, sizeof(int), comparar);
    if (tamanho % 2 == 0)
    {
        int indice1 = tamanho / 2 - 1;
        int indice2 = tamanho / 2;
        return (numeros[indice1] + numeros[indice2]) / 2.0;
    }
    else
    {
        int indice = tamanho / 2;
        return numeros[indice];
    }
}

int calcularModa(int tamanho)
{
    int moda, i, j;
    int numeros[tamanho];
    int frequenciaMaxima;

   
    printf("Digite os %d numeros:\n", tamanho);
    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", &numeros[i]);
    }

    frequenciaMaxima = 0;

    moda = 0;

    for (i = 0; i < tamanho; i++)
    {
        int frequencia = 0;

        for (j = 0; j < tamanho; j++)
        {
            if (numeros[j] == numeros[i])
            {
                frequencia++;
            }
        }

        if (frequencia > frequenciaMaxima)
        {
            frequenciaMaxima = frequencia;
            moda = numeros[i];
        }
    }

    return moda;
}

float calcularVariancia(int qtdNumeros)
{
    float numeros[100];
    int tamanho = 0, opcao;
    float media = 0;
    int i;
    
    printf("Digite os numeros:\n");
    for (i = 0; i < qtdNumeros; i++) {
        scanf("%f", &numeros[i]);
        tamanho++;
        media += numeros[i];
    }

    printf("Deseja fornecer a media? (1 - Sim, 0 - Nao): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Digite a media: ");
        scanf("%f", &media);
    } else {
        media /= tamanho;
    }
    
    float soma = 0;

    for (i = 0; i < tamanho; i++) {
        soma += pow(numeros[i] - media, 2);
    }

    return soma / tamanho;
}

float calcularDesvioPadrao(int qtdNumeros)
{
    int opcao;
    float numeros[100];
    int tamanho = 0;
    float media = 0;
    int i;
    
    printf("Digite os numeros:\n");
        for (i = 0; i < qtdNumeros; i++) {
            scanf("%f", &numeros[i]);
            tamanho++;
            media += numeros[i];
        }

        printf("Deseja fornecer a media? (1 - Sim, 0 - Nao): ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite a media: ");
            scanf("%f", &media);
        } else {
            media /= tamanho;
        }
    
    float soma = 0;

    for (i = 0; i < tamanho; i++) {
        soma += pow(numeros[i] - media, 2);
    }

    float desvio = soma / tamanho;
    return sqrt(desvio);
}

float calcularEscoreZ(float valor, float media, float desvioPadrao)
{
    float escoreZ = (valor - media) / desvioPadrao;
    return escoreZ;
}


float calcularErroMedia() {
    int T;
    int grauConfianca, opcaoErro;
    float desvPopul, erroDefinido, erro;
        
    printf("Digite o grau de confiança:\n");
    printf("1. 90%%\n");
    printf("2. 95%%\n");
    printf("3. 99%%\n");
    printf("Opcao: ");
    scanf("%d", &grauConfianca);

    float z;
    if (grauConfianca == 1) {
        z = 1.645;
    } else if (grauConfianca == 2) {
        z = 1.96;
    } else if (grauConfianca == 3) {
        z = 2.575;
    } else {
        printf("Opcao invalida.\n");
        return 0;
    }

    printf("Voce tem umm erro definido? (1 - Sim, 2 - Nao): \n");
    scanf("%d", &opcaoErro);
    if(opcaoErro == 1){
        printf("Digite o valor do erro: \n");
        scanf("%f", &erroDefinido);
        return erroDefinido;
    }else if(opcaoErro == 2){
        printf("Digite o valor do desvio padrao: \n");
        scanf("%f", &desvPopul);
        printf("Digite o tamanho da Amostra: \n");
        scanf("%d", &T);
        erro = (z * (desvPopul / sqrt(T)));
        printf("O valor do Erro e: %2f \n", erro);
        return erro;
    }else{
        printf("Opcao invalida.\n");
        return 0;
    }
}

float calcularErroProporcao(float proporcao2)
{
    int Tamostra;
    int grauConfianca;
    float proporcaoErro2;

    
    printf("Digite o grau de confiança:\n");
    printf("1. 90%%\n");
    printf("2. 95%%\n");
    printf("3. 99%%\n");
    printf("Opcao: ");
    scanf("%d", &grauConfianca);

    float z;
    if (grauConfianca == 1) {
        z = 1.645;
    } else if (grauConfianca == 2) {
        z = 1.96;
    } else if (grauConfianca == 3) {
        z = 2.575;
    } else {
        printf("Opcao invalida.\n");
        return 0;
    }
    
    printf("Digite o tamanho da Amostra novamente: \n");
    scanf("%d0", &Tamostra);
    proporcaoErro2 = z*sqrt((proporcao2*(1-proporcao2))/Tamostra);
    return proporcaoErro2; 
}  

float calcularProporcao(){
    float valor, sucesso, amostra;

    printf("Digite o valor do sucesso: \n");
    scanf("%f", &sucesso);
    printf("Digite o tamanho da Amostra: \n");
    scanf("%f", &amostra);
    valor = (sucesso / amostra);
    
    return valor;
}

float calcularTamanhoMedia(){
    int grauConfianca;
    float desvio, margemMedia, tamanhoMedia;

    printf("Digite o grau de confiança:\n");
    printf("1. 90%%\n");
    printf("2. 95%%\n");
    printf("3. 99%%\n");
    printf("Opcao: ");
    scanf("%d", &grauConfianca);

    float z;
    if (grauConfianca == 1) {
        z = 1.645;
    } else if (grauConfianca == 2) {
        z = 1.96;
    } else if (grauConfianca == 3) {
        z = 2.575;
    } else {
        printf("Opcao invalida.\n");
        return 0;
    }

    printf("Digite o Desvio Padrao: \n");
    scanf("%f", &desvio);

    printf("Digite a Margem de Erro da Media: \n");
    scanf("%f", &margemMedia);

    tamanhoMedia = ((z*desvio)/margemMedia); 
    tamanhoMedia = pow(tamanhoMedia, 2);
    return tamanhoMedia;

}

float calcularTamanhoProporcao(){
    int grauConfianca, opcaoProporcao;
    float desvio, margemProporcao, tamanhoProporcao, tamanhoProporcao2, proporcao, proporcao2, grauElevado, margemElevado;

    printf("Voce tem um valor de proporcao definido? (1 - Sim, 2 - Nao): \n");
    scanf("%d", &opcaoProporcao);
    if(opcaoProporcao == 1){
        printf("Digite o valor da proporcao: \n");
        scanf("%f", &proporcao);
        printf("Digite o grau de confiança: \n");
        printf("1. 90%%\n");
        printf("2. 95%%\n");
        printf("3. 99%%\n");
        printf("Opcao: ");
        scanf("%d", &grauConfianca);

        float z;
        if (grauConfianca == 1) {
            z = 1.645;
        } else if (grauConfianca == 2) {
            z = 1.96;
        } else if (grauConfianca == 3) {
            z = 2.575;
        } else {
            printf("Opcao invalida.\n");
            return 0;
        }

        printf("Digite a Margem de Erro da Proporcao: \n");
        scanf("%f", &margemProporcao);

        grauElevado = pow(z, 2);
        margemElevado = pow(margemProporcao, 2);

        tamanhoProporcao = ((grauElevado * (proporcao *(1-proporcao)))/ margemElevado);
        return tamanhoProporcao;
    }else if(opcaoProporcao == 2){
        printf("Nao existe um valor de proporcao, por isso o valor que sera usado no lugar e: 0.5");
        proporcao2 = 0.5;
        printf("Digite o grau de confiança: \n");
        printf("1. 90%%\n");
        printf("2. 95%%\n");
        printf("3. 99%%\n");
        printf("Opcao: ");
        scanf("%d", &grauConfianca);

        float z;
        if (grauConfianca == 1) {
            z = 1.645;
        } else if (grauConfianca == 2) {
            z = 1.96;
        } else if (grauConfianca == 3) {
            z = 2.575;
        } else {
            printf("Opcao invalida.\n");
            return 0;
        }

        printf("Digite a Margem de Erro da Proporcao: \n");
        scanf("%f", &margemProporcao);

        grauElevado = pow(z, 2);
        margemElevado = pow(margemProporcao, 2);

        tamanhoProporcao2 = ((grauElevado * (proporcao2 *(1-proporcao2)))/ margemElevado);
        return tamanhoProporcao2;

    }else{
        printf("Opcao invalida.\n");
        return 0;
    }
    

}
