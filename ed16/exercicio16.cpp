
#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>

class Erro
{
private:
    int errorCode;
    std::string errorMessage;

public:
    Erro() : errorCode(0), errorMessage("") {}
    virtual ~Erro() {}

    void setErro(int code, const std::string& message = "")
    {
        errorCode = code;
        errorMessage = message;
    }

    int getErro() const
    {
        return errorCode;
    }

    std::string getErrorMessage() const
    {
        return errorMessage;
    }

    bool hasErro() const
    {
        return errorCode != 0;
    }
};

#endif // _ERRO_H_

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct s_intArray
{
    int length;
    int *data;
} intArray;

typedef intArray* ref_intArray;

void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}

ref_intArray criarArranjoInteiros(int length) {
    ref_intArray newArray = (ref_intArray)malloc(sizeof(intArray));
    if (newArray == NULL) {
        return NULL;
    }
    newArray->length = length;
    if (length > 0) {
        newArray->data = (int*)malloc(length * sizeof(int));
        if (newArray->data == NULL) {
            free(newArray);
            return NULL;
        }
    } else {
        newArray->data = NULL;
    }
    return newArray;
}

void destruirArranjoInteiros(ref_intArray arr) {
    if (arr != NULL) {
        if (arr->data != NULL) {
            free(arr->data);
        }
        free(arr);
    }
}

// 01.) Funcao para acrescentar valor ao final de um arranjo, por meio de apontador.
int* array_push_back (int *array, int value)
{
    ref_intArray current_array = (ref_intArray)array;

    if (current_array == NULL) {
        ref_intArray newArray = criarArranjoInteiros(1);
        if (newArray != NULL) {
            newArray->data[0] = value;
        }
        return (int*)newArray;
    }

    int newLength = current_array->length + 1;
    ref_intArray newArray = criarArranjoInteiros(newLength);
    if (newArray == NULL) {
        return NULL;
    }

    for (int i = 0; i < current_array->length; ++i) {
        newArray->data[i] = current_array->data[i];
    }
    newArray->data[current_array->length] = value;

    destruirArranjoInteiros(current_array);
    return (int*)newArray;
}

// 02.) Funcao para remover valor do final de um arranjo, por meio de apontador.
int* array_pop_back (int *array)
{
    ref_intArray current_array = (ref_intArray)array;

    if (current_array == NULL || current_array->length == 0) {
        destruirArranjoInteiros(current_array);
        return NULL;
    }

    int newLength = current_array->length - 1;
    if (newLength == 0) {
        destruirArranjoInteiros(current_array);
        return NULL;
    }

    ref_intArray newArray = criarArranjoInteiros(newLength);
    if (newArray == NULL) {
        return NULL;
    }

    for (int i = 0; i < newLength; ++i) {
        newArray->data[i] = current_array->data[i];
    }

    destruirArranjoInteiros(current_array);
    return (int*)newArray;
}

// 03.) Funcao para acrescentar valor ao início de um arranjo, por meio de apontador.
int* array_push_front (int value, int *array)
{
    ref_intArray current_array = (ref_intArray)array;

    if (current_array == NULL) {
        ref_intArray newArray = criarArranjoInteiros(1);
        if (newArray != NULL) {
            newArray->data[0] = value;
        }
        return (int*)newArray;
    }

    int newLength = current_array->length + 1;
    ref_intArray newArray = criarArranjoInteiros(newLength);
    if (newArray == NULL) {
        return NULL;
    }

    newArray->data[0] = value;
    for (int i = 0; i < current_array->length; ++i) {
        newArray->data[i+1] = current_array->data[i];
    }

    destruirArranjoInteiros(current_array);
    return (int*)newArray;
}

// 04.) Funcao para remover valor do início de um arranjo, por meio de apontador.
int* array_pop_front (int *array)
{
    ref_intArray current_array = (ref_intArray)array;

    if (current_array == NULL || current_array->length == 0) {
        destruirArranjoInteiros(current_array);
        return NULL;
    }

    int newLength = current_array->length - 1;
    if (newLength == 0) {
        destruirArranjoInteiros(current_array);
        return NULL;
    }

    ref_intArray newArray = criarArranjoInteiros(newLength);
    if (newArray == NULL) {
        return NULL;
    }

    for (int i = 0; i < newLength; ++i) {
        newArray->data[i] = current_array->data[i+1];
    }

    destruirArranjoInteiros(current_array);
    return (int*)newArray;
}

// 05.) Funcao para acrescentar valor no meio (aproximadamente) de um arranjo, por meio de apontador.
int* array_push_mid (int *array, int value)
{
    ref_intArray current_array = (ref_intArray)array;

    if (current_array == NULL) {
        ref_intArray newArray = criarArranjoInteiros(1);
        if (newArray != NULL) {
            newArray->data[0] = value;
        }
        return (int*)newArray;
    }

    int newLength = current_array->length + 1;
    ref_intArray newArray = criarArranjoInteiros(newLength);
    if (newArray == NULL) {
        return NULL;
    }

    int mid = current_array->length / 2;

    for (int i = 0; i < mid; ++i) {
        newArray->data[i] = current_array->data[i];
    }
    newArray->data[mid] = value;
    for (int i = mid; i < current_array->length; ++i) {
        newArray->data[i+1] = current_array->data[i];
    }

    destruirArranjoInteiros(current_array);
    return (int*)newArray;
}

// 06.) Funcao para remover valor do meio (aproximadamente) de um arranjo, por meio de apontador.
int* array_pop_mid (int *array)
{
    ref_intArray current_array = (ref_intArray)array;

    if (current_array == NULL || current_array->length == 0) {
        destruirArranjoInteiros(current_array);
        return NULL;
    }

    int newLength = current_array->length - 1;
    if (newLength == 0) {
        destruirArranjoInteiros(current_array);
        return NULL;
    }

    ref_intArray newArray = criarArranjoInteiros(newLength);
    if (newArray == NULL) {
        return NULL;
    }

    int mid = current_array->length / 2;

    for (int i = 0; i < mid; ++i) {
        newArray->data[i] = current_array->data[i];
    }
    for (int i = mid; i < newLength; ++i) {
        newArray->data[i] = current_array->data[i+1];
    }

    destruirArranjoInteiros(current_array);
    return (int*)newArray;
}

// 07.) Funcao para comparar arranjos de inteiros por meio de apontadores.
int intArray_cmp (ref_intArray p, ref_intArray q)
{
    if (p == NULL && q == NULL) return 0;
    if (p == NULL) return -1;
    if (q == NULL) return 1;

    if (p->length < q->length) return -1;
    if (p->length > q->length) return 1;

    for (int i = 0; i < p->length; ++i) {
        if (p->data[i] < q->data[i]) return -1;
        if (p->data[i] > q->data[i]) return 1;
    }
    return 0;
}

// 08.) Funcao para juntar um arranjo de inteiros ao final de outro por meio de apontadores.
ref_intArray intArray_cat (ref_intArray p, ref_intArray q)
{
    if (p == NULL && q == NULL) return NULL;

    int p_length = (p != NULL) ? p->length : 0;
    int q_length = (q != NULL) ? q->length : 0;
    int newLength = p_length + q_length;

    ref_intArray newArray = criarArranjoInteiros(newLength);
    if (newArray == NULL) {
        return NULL;
    }

    for (int i = 0; i < p_length; ++i) {
        newArray->data[i] = p->data[i];
    }
    for (int i = 0; i < q_length; ++i) {
        newArray->data[p_length + i] = q->data[i];
    }

    return newArray;
}

// 09.) Funcao para procurar pela primeira ocorrencia de valor em arranjo por meio de apontador.
ref_intArray intArray_seek (ref_intArray a, int x)
{
    if (a == NULL || a->length == 0) return NULL;

    for (int i = 0; i < a->length; ++i) {
        if (a->data[i] == x) {
            ref_intArray found = criarArranjoInteiros(1);
            if (found != NULL) {
                found->data[0] = a->data[i];
            }
            return found;
        }
    }
    return NULL;
}

// 10.) Funcao para separar sequencia de valores em arranjo por meio de apontador.
ref_intArray intArray_sub (ref_intArray a, int start, int size)
{
    if (a == NULL || a->length == 0 || start < 0 || size <= 0 || start + size > a->length) {
        return NULL;
    }

    ref_intArray subArray = criarArranjoInteiros(size);
    if (subArray == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        subArray->data[i] = a->data[start + i];
    }
    return subArray;
}

// E1.) Funcao para intercalar arranjos de inteiros, usando um valor de cada por vez, por meio de apontadores.
ref_intArray intArray_merge (ref_intArray p, ref_intArray q)
{
    if (p == NULL && q == NULL) return NULL;

    int p_length = (p != NULL) ? p->length : 0;
    int q_length = (q != NULL) ? q->length : 0;
    int newLength = p_length + q_length;

    ref_intArray newArray = criarArranjoInteiros(newLength);
    if (newArray == NULL) {
        return NULL;
    }

    int p_idx = 0;
    int q_idx = 0;
    int new_idx = 0;

    while (p_idx < p_length || q_idx < q_length) {
        if (p_idx < p_length) {
            newArray->data[new_idx++] = p->data[p_idx++];
        }
        if (q_idx < q_length) {
            newArray->data[new_idx++] = q->data[q_idx++];
        }
    }
    return newArray;
}

// E2.) Funcao para mesclar arranjos de inteiros em ordem de decrescente por meio de apontadores.
ref_intArray intArray_mergeDown (ref_intArray p, ref_intArray q)
{
    ref_intArray combined = intArray_cat(p, q);
    if (combined == NULL) return NULL;

    for (int i = 0; i < combined->length - 1; ++i) {
        for (int j = 0; j < combined->length - 1 - i; ++j) {
            if (combined->data[j] < combined->data[j+1]) {
                int temp = combined->data[j];
                combined->data[j] = combined->data[j+1];
                combined->data[j+1] = temp;
            }
        }
    }
    return combined;
}

void printIntArray(const std::string& label, ref_intArray arr) {
    std::cout << label << ": ";
    if (arr == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }
    std::cout << "Length = " << arr->length << ", Data = [";
    for (int i = 0; i < arr->length; ++i) {
        std::cout << arr->data[i] << (i == arr->length - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

void method_00 ()
{
    cout << "\nMethod_00 - nao faz nada.\n" << endl;
    pause("Apertar ENTER para continuar");
}

void method_01_test ()
{
    cout << "\nMethod_01 - Testar array_push_back e array_pop_back\n" << endl;

    ref_intArray arr1 = NULL;
    printIntArray("Initial arr1", arr1);
    arr1 = (ref_intArray)array_push_back((int*)arr1, 10);
    printIntArray("arr1 after push_back(10)", arr1);
    arr1 = (ref_intArray)array_push_back((int*)arr1, 20);
    printIntArray("arr1 after push_back(20)", arr1);
    arr1 = (ref_intArray)array_push_back((int*)arr1, 30);
    printIntArray("arr1 after push_back(30)", arr1);

    arr1 = (ref_intArray)array_pop_back((int*)arr1);
    printIntArray("arr1 after pop_back", arr1);
    arr1 = (ref_intArray)array_pop_back((int*)arr1);
    printIntArray("arr1 after pop_back", arr1);
    arr1 = (ref_intArray)array_pop_back((int*)arr1);
    printIntArray("arr1 after pop_back", arr1);
    arr1 = (ref_intArray)array_pop_back((int*)arr1);
    printIntArray("arr1 after pop_back (empty)", arr1);
    destruirArranjoInteiros(arr1);

    pause ("Apertar ENTER para continuar");
}

void method_02_test()
{
    cout << "\nMethod_02 - Testar array_push_front e array_pop_front\n" << endl;

    ref_intArray arr2 = NULL;
    printIntArray("Initial arr2", arr2);
    arr2 = (ref_intArray)array_push_front(5, (int*)arr2);
    printIntArray("arr2 after push_front(5)", arr2);
    arr2 = (ref_intArray)array_push_front(1, (int*)arr2);
    printIntArray("arr2 after push_front(1)", arr2);
    arr2 = (ref_intArray)array_push_front(0, (int*)arr2);
    printIntArray("arr2 after push_front(0)", arr2);

    arr2 = (ref_intArray)array_pop_front((int*)arr2);
    printIntArray("arr2 after pop_front", arr2);
    arr2 = (ref_intArray)array_pop_front((int*)arr2);
    printIntArray("arr2 after pop_front", arr2);
    arr2 = (ref_intArray)array_pop_front((int*)arr2);
    printIntArray("arr2 after pop_front", arr2);
    arr2 = (ref_intArray)array_pop_front((int*)arr2);
    printIntArray("arr2 after pop_front (empty)", arr2);
    destruirArranjoInteiros(arr2);

    pause("Apertar ENTER para continuar");
}

void method_03_test()
{
    cout << "\nMethod_03 - Testar array_push_mid e array_pop_mid\n" << endl;

    ref_intArray arr3 = criarArranjoInteiros(3);
    if (arr3) {
        arr3->data[0] = 10;
        arr3->data[1] = 20;
        arr3->data[2] = 30;
    }
    printIntArray("Initial arr3", arr3);

    arr3 = (ref_intArray)array_push_mid((int*)arr3, 15);
    printIntArray("arr3 after push_mid(15)", arr3);
    arr3 = (ref_intArray)array_push_mid((int*)arr3, 25);
    printIntArray("arr3 after push_mid(25)", arr3);

    arr3 = (ref_intArray)array_pop_mid((int*)arr3);
    printIntArray("arr3 after pop_mid", arr3);
    arr3 = (ref_intArray)array_pop_mid((int*)arr3);
    printIntArray("arr3 after pop_mid", arr3);
    arr3 = (ref_intArray)array_pop_mid((int*)arr3);
    printIntArray("arr3 after pop_mid", arr3);
    arr3 = (ref_intArray)array_pop_mid((int*)arr3);
    printIntArray("arr3 after pop_mid", arr3);
    arr3 = (ref_intArray)array_pop_mid((int*)arr3);
    printIntArray("arr3 after pop_mid (empty)", arr3);
    destruirArranjoInteiros(arr3);

    pause("Apertar ENTER para continuar");
}

void method_07_test() // Test function for intArray_cmp (Ex. 07)
{
    cout << "\nMethod_07 - Testar intArray_cmp (Ex. 07)\n" << endl;

    ref_intArray arrA = criarArranjoInteiros(3);
    if (arrA) { arrA->data[0]=1; arrA->data[1]=2; arrA->data[2]=3; }
    ref_intArray arrB = criarArranjoInteiros(3);
    if (arrB) { arrB->data[0]=1; arrB->data[1]=2; arrB->data[2]=3; }
    ref_intArray arrC = criarArranjoInteiros(2);
    if (arrC) { arrC->data[0]=1; arrC->data[1]=2; }
    ref_intArray arrD = criarArranjoInteiros(3);
    if (arrD) { arrD->data[0]=1; arrD->data[1]=5; arrD->data[2]=3; }

    printIntArray("arrA", arrA);
    printIntArray("arrB", arrB);
    printIntArray("arrC", arrC);
    printIntArray("arrD", arrD);

    cout << "intArray_cmp(arrA, arrB): " << intArray_cmp(arrA, arrB) << " (Expected 0)" << endl;
    cout << "intArray_cmp(arrA, arrC): " << intArray_cmp(arrA, arrC) << " (Expected 1)" << endl;
    cout << "intArray_cmp(arrC, arrA): " << intArray_cmp(arrC, arrA) << " (Expected -1)" << endl;
    cout << "intArray_cmp(arrA, arrD): " << intArray_cmp(arrA, arrD) << " (Expected -1)" << endl;
    cout << "intArray_cmp(arrD, arrA): " << intArray_cmp(arrD, arrA) << " (Expected 1)" << endl;

    destruirArranjoInteiros(arrA);
    destruirArranjoInteiros(arrB);
    destruirArranjoInteiros(arrC);
    destruirArranjoInteiros(arrD);

    pause("Apertar ENTER para continuar");
}

void method_08_test() // Test function for intArray_cat (Ex. 08)
{
    cout << "\nMethod_08 - Testar intArray_cat (Ex. 08)\n" << endl;

    ref_intArray arrP = criarArranjoInteiros(3);
    if (arrP) { arrP->data[0]=1; arrP->data[1]=2; arrP->data[2]=3; }
    ref_intArray arrQ = criarArranjoInteiros(2);
    if (arrQ) { arrQ->data[0]=4; arrQ->data[1]=5; }

    printIntArray("arrP", arrP);
    printIntArray("arrQ", arrQ);

    ref_intArray combined = intArray_cat(arrP, arrQ);
    printIntArray("intArray_cat(arrP, arrQ)", combined);

    destruirArranjoInteiros(arrP);
    destruirArranjoInteiros(arrQ);
    destruirArranjoInteiros(combined);

    pause("Apertar ENTER para continuar");
}

void method_09_test() // Test function for intArray_seek (Ex. 09)
{
    cout << "\nMethod_09 - Testar intArray_seek (Ex. 09)\n" << endl;

    ref_intArray arr_seek = criarArranjoInteiros(5);
    if (arr_seek) { arr_seek->data[0]=10; arr_seek->data[1]=20; arr_seek->data[2]=30; arr_seek->data[3]=20; arr_seek->data[4]=50; }
    printIntArray("arr_seek", arr_seek);

    ref_intArray found = intArray_seek(arr_seek, 30);
    printIntArray("Found 30", found);
    destruirArranjoInteiros(found);

    found = intArray_seek(arr_seek, 20);
    printIntArray("Found 20 (first occurrence)", found);
    destruirArranjoInteiros(found);

    found = intArray_seek(arr_seek, 100);
    printIntArray("Found 100", found);
    destruirArranjoInteiros(found);

    destruirArranjoInteiros(arr_seek);

    pause("Apertar ENTER para continuar");
}

void method_10_test() // Test function for intArray_sub (Ex. 10)
{
    cout << "\nMethod_10 - Testar intArray_sub (Ex. 10)\n" << endl;

    ref_intArray arr_sub = criarArranjoInteiros(5);
    if (arr_sub) { arr_sub->data[0]=10; arr_sub->data[1]=20; arr_sub->data[2]=30; arr_sub->data[3]=40; arr_sub->data[4]=50; }
    printIntArray("arr_sub", arr_sub);

    ref_intArray sub = intArray_sub(arr_sub, 1, 3);
    printIntArray("Sub-array from index 1, size 3", sub);
    destruirArranjoInteiros(sub);

    sub = intArray_sub(arr_sub, 0, 2);
    printIntArray("Sub-array from index 0, size 2", sub);
    destruirArranjoInteiros(sub);

    sub = intArray_sub(arr_sub, 4, 1);
    printIntArray("Sub-array from index 4, size 1", sub);
    destruirArranjoInteiros(sub);

    sub = intArray_sub(arr_sub, 3, 3);
    printIntArray("Sub-array (invalid)", sub);
    destruirArranjoInteiros(sub);

    pause("Apertar ENTER para continuar");
}

void method_E1_test() // Test function for intArray_merge (Ex. E1)
{
    cout << "\nMethod_E1 - Testar intArray_merge (Ex. E1)\n" << endl;

    ref_intArray p_merge = criarArranjoInteiros(3);
    if (p_merge) { p_merge->data[0]=1; p_merge->data[1]=3; p_merge->data[2]=5; }
    ref_intArray q_merge = criarArranjoInteiros(3);
    if (q_merge) { q_merge->data[0]=2; q_merge->data[1]=4; q_merge->data[2]=6; }

    printIntArray("p_merge", p_merge);
    printIntArray("q_merge", q_merge);

    ref_intArray merged = intArray_merge(p_merge, q_merge);
    printIntArray("intArray_merge (interleave)", merged);
    destruirArranjoInteiros(merged);

    destruirArranjoInteiros(p_merge);
    destruirArranjoInteiros(q_merge);

    pause("Apertar ENTER para continuar");
}

void method_E2_test() // Test function for intArray_mergeDown (Ex. E2)
{
    cout << "\nMethod_E2 - Testar intArray_mergeDown (Ex. E2)\n" << endl;

    ref_intArray p_merge_down = criarArranjoInteiros(3);
    if (p_merge_down) { p_merge_down->data[0]=10; p_merge_down->data[1]=30; p_merge_down->data[2]=20; }
    ref_intArray q_merge_down = criarArranjoInteiros(3);
    if (q_merge_down) { q_merge_down->data[0]=60; q_merge_down->data[1]=40; q_merge_down->data[2]=50; }

    printIntArray("p_merge_down", p_merge_down);
    printIntArray("q_merge_down", q_merge_down);

    ref_intArray merged_down = intArray_mergeDown(p_merge_down, q_merge_down);
    printIntArray("intArray_mergeDown (descending)", merged_down);
    destruirArranjoInteiros(merged_down);

    destruirArranjoInteiros(p_merge_down);
    destruirArranjoInteiros(q_merge_down);

    pause("Apertar ENTER para continuar");
}


// Funcao principal.
int main (int argc, char** argv)
{
    // definir dado
    int x = 0;

    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1600 - Programa - v0.0\n" << endl;
        // mostrar opcoes
        cout << "Opcoes" << endl;
        cout << "0- parar" << endl;
        cout << "1- array_push_back / array_pop_back" << endl;
        cout << "2- array_push_front / array_pop_front" << endl;
        cout << "3- array_push_mid / array_pop_mid" << endl;
        cout << "7- intArray_cmp (Ex. 07)" << endl;
        cout << "8- intArray_cat (Ex. 08)" << endl;
        cout << "9- intArray_seek (Ex. 09)" << endl;
        cout << "10- intArray_sub (Ex. 10)" << endl;
        cout << "11- intArray_merge (Extra 1)" << endl;
        cout << "12- intArray_mergeDown (Extra 2)" << endl;


        // ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        // escolher acao
        switch (x)
        {
            case 0:
                method_00 ();
                break;
            case 1:
                method_01_test ();
                break;
            case 2:
                method_02_test ();
                break;
            case 3:
                method_03_test ();
                break;
            case 7:
                method_07_test ();
                break;
            case 8:
                method_08_test ();
                break;
            case 9:
                method_09_test ();
                break;
            case 10:
                method_10_test ();
                break;
            case 11:
                method_E1_test ();
                break;
            case 12:
                method_E2_test ();
                break;
            default:
                cout << endl << "ERRO: Valor invalido." << endl;
        } // end switch

    } while (x != 0);

    // encerrar
    pause ("Apertar ENTER para terminar");

    return (0);

} // end main (