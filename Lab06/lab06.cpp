#include <iostream>
#include <string.h>

class Matrix
{
private:
    int m, n;
    float values[][20];
public:
    Matrix(int m = 1, int n = 1);
    ~Matrix();
    float getValues(int, int);
    void setValues(int, int, float);
    Matrix operator +( const Matrix &);
    Matrix operator *(const Matrix &);
    Matrix operator -(const Matrix &);
    Matrix operator =(const Matrix &);
    void operator ++();
    void operator --();
    void operator +=(const Matrix &);
    void operator *=(const Matrix &);
    void operator -=(const Matrix &);
};

Matrix::Matrix(int m, int n){
    values[n][m];
}

Matrix::~Matrix(){
    delete[] values;
}

float Matrix::getValues(int i, int j){
      return values[i][j];
}

void Matrix::setValues(int i, int j, float elm){
    values[i][j] = elm;
}
//Матрицуудыг хооронд нэмэх
Matrix Matrix::operator +(Matrix &A){

    Matrix C(this.m + A->m, this.n + A->n);
    if(!(this.m == A->m && this.n == A->n)){
        cout<<"Nemeh bolomjgui matrix.\n";
    }

    for(int i = 0; i < A->m; i++){
        for(int j = 0; j < A->n; j++){
            C[i[j] = this.getValues(i, j) + A->getValues(i, j);
        }
    }

    return C;

}

//Матрицыг тогтмол тоогоор нэмэгдүүлэх
Matrix Matrix::operator+(){

    Matrix C(this.m + A->m, this.n + A->n);
    if(!(this.m == A->m && this.n == A->n)){
        cout<<"Nemeh bolomjgui matrix.\n";
    }

    for(int i = 0; i < A->m; i++){
        for(int j = 0; j < A->n; j++){
            C[i[j] = this.getValues(i, j) + A->getValues(i, j);
        }
    }

    return C;

}

//1. + нэмэх(хоёр матрицыг нэмнэ), хоёр янзаар тодорхойлно: a)R = R1 + 12.5(float) b) R = R1 + R2

//2. * үржих (хоёр матрицийг үржээд үржвэрийг буцаана)
//3. - хасах (хоёр матрицийг хасаад ялгаварыг буцаана)
//4. = нэг матрицийн объектыг нөгөөд утга оноох
//5. ++ нэгээр нэмэгдүүлэх
//6. -- нэгээр хорогдуулах
//7. +=
//8. -=
//9. *=
//10. [][] тухайн нүдэндэх элементийн утга авах
//11. Матрицыг хөрвүүлэх: А матрицын мөрийг багана, баганыг мөр болгоход үүсэх матрицыг А матрицыг хөрвүүлсэн матриц гэнэ (өөрөө ямар нэг операторыг хайж олоод дахин тодорхойлно)

int main(){




    return 0;
}




