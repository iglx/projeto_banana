#include <iostream>
#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>
#include "funcoes.h"

using namespace std;
using namespace cv;

int main()
{

    Mat img, bin, result, img2, result2;
     //int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
     int contVerde = 0;
     int contAmerelo = 0;
     int cont=0;

//Binarizar
img = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\imgs\\6.jpg",0);
img2 = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\imgs\\6.jpg",1);
bin = img.clone();
result = img2.clone();
result2 = img2.clone();


//Binarizando
for(int i=0; i<img.rows; i++){
    for(int j=0; j<img.cols; j++){
        if(img.at<uchar>(i,j)>80)
        {
            bin.at<uchar>(i,j)=255;
        }else
        {
            bin.at<uchar>(i,j)=0;
        }
    }
}

//Destacando a banana
for(int i=0; i<result.rows; i++){
    for(int j=0; j<result.cols; j++){
        if(bin.at<uchar>(i,j)==0){
            result.at<Vec3b>(i,j)[2]=255;
            result.at<Vec3b>(i,j)[1]=255;
            result.at<Vec3b>(i,j)[0]=255;
        }else{
            result.at<Vec3b>(i,j)[2]=img2.at<Vec3b>(i,j)[2];
            result.at<Vec3b>(i,j)[1]=img2.at<Vec3b>(i,j)[1];
            result.at<Vec3b>(i,j)[0]=img2.at<Vec3b>(i,j)[0];
            cont++;
        }
    }
}

namedWindow("imagemDestacada1");
imshow("imagemDestacada1",result);

//printf("shushauhsuau");
//Binarizando colorida
for(int i=0; i<result.rows; i++){
    for(int j=0; j<result.cols; j++){
        if(result.at<Vec3b>(i,j)[2]>80)
        {
            result2.at<Vec3b>(i,j)[2]=255;
        }if(result.at<Vec3b>(i,j)[1]>80)
        {
            result.at<Vec3b>(i,j)[1]=255;
        }if(result.at<Vec3b>(i,j)[0]>80)
        {
            result.at<Vec3b>(i,j)[2]=255;
        }else{
            result.at<Vec3b>(i,j)[2]=0;
        }
    }
}


//Pesquisando as cores individuais da imagem
//Analizando imagem
        for (int i=0;i<img2.rows; i++){
            for(int j=0;j<img2.cols; j++){
                Vec3b color = result.at<Vec3b>(Point(j,i));
                //Verde
                if(color[0]>=10 && color[0]<=90 && color[1]==255 && color[2]==0){
                    contVerde++;
                }
                //Amarelo
                if(color[0]>=70 && color[0]<=190 && color[1]==255 && color[2]==255){
                    contAmerelo++;
                }
            }
        }


        printf("\nPixels Verdes: %d\n",contVerde);
        printf("Pixels Amarelos: %d\n",contAmerelo);
       // printf("Soma dos Pixels: %d\n",contAmerelo+contVerde);
        printf("Todos os pixels: %d\n",cont);


        printf("Porcentagem verde %0.1f% \n",porcentagem(contVerde, cont));
        printf("Porcentagem amarelos %0.1f%\n",porcentagem(contAmerelo, cont));


        float verde = porcentagem(contVerde, cont);
        float amarelo = porcentagem(contAmerelo, cont);

        if(verde>=70 && amarelo<=29)
        {
            printf("VERDE\n");
        }





namedWindow("ImagemOriginal");
imshow("ImagemOriginal",img2);

namedWindow("ImagemOriginalTons");
imshow("ImagemOriginalTons",img);

namedWindow("ImagemBinarizada");
imshow("ImagemBinarizada",bin);

namedWindow("Destacada");
imshow("Destacada",result);

namedWindow("teste");
imshow("teste",result2);


waitKey(0);

destroyWindow("tela1");

return 0;
}
