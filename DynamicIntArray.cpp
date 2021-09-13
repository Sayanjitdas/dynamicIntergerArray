// structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct DynamicArr {
    int* dynamicArr;
    int capacity;
    int size;
};

DynamicArr* CreateDynamicArray() {
    DynamicArr* ptrArr = new DynamicArr;
    ptrArr->capacity = 2;
    ptrArr->size = 0;
    ptrArr->dynamicArr = new int[ptrArr->capacity];

    return ptrArr;
}

void ResizeDynamicArray(DynamicArr* dynaArr) {
    int* tempArr = new int[dynaArr->capacity];
    for (int i = 0; i < dynaArr->size; i++) {
        tempArr[i] = dynaArr->dynamicArr[i];
    }

    delete[] dynaArr->dynamicArr;
    dynaArr->capacity += 1;
    dynaArr->dynamicArr = new int[dynaArr->capacity];

    for (int i = 0; i < dynaArr->size; i++) {
        dynaArr->dynamicArr[i] = tempArr[i];
    }

    delete[] tempArr;
}

void DeleteDynamicArray(DynamicArr* dynaArr) {
    delete[] dynaArr->dynamicArr;
    delete dynaArr;
}

void AppendElement(DynamicArr* dynaArr,const int element) {
    
    if (dynaArr->size < dynaArr->capacity) {
        dynaArr->dynamicArr[dynaArr->size] = element;
        dynaArr->size += 1;
       
    }
    else {
         ResizeDynamicArray(dynaArr);
         dynaArr->dynamicArr[dynaArr->size] = element;
         dynaArr->size += 1;
    }
}

void InsertElement(DynamicArr* dynaArr,const int index,const int element) {
    if (dynaArr->size >= dynaArr->capacity) {
        ResizeDynamicArray(dynaArr);
    }
    if (index < dynaArr->size && index >= 0) {
        for (int i = dynaArr->size; i >= index + 1; i--) {
            dynaArr->dynamicArr[i] = dynaArr->dynamicArr[i - 1];
        }
        dynaArr->dynamicArr[index] = element;
        dynaArr->size += 1;
    }
    else {
        cout << "Array index out of range (array index starts from 0)" << endl;
    }
}

void ReplaceElement(DynamicArr* dynaArr, const int index, const int element) {
    dynaArr->dynamicArr[index] = element;
}

void RemoveElement(DynamicArr* dynaArr, int index) {

    if (index < dynaArr->size && index >= 0) {
        for (int i = index; i < dynaArr->size; i++) {
            dynaArr->dynamicArr[i] = dynaArr->dynamicArr[i+1];
        }
        dynaArr->size -= 1;
    }
    else {
        cout << "Array index out of range (array index starts from 0)" << endl;
    }
}

void PrintArray(const DynamicArr* dynaArr) {
    
    for (int i = 0; i < dynaArr->size; i++) {
        cout << dynaArr->dynamicArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    DynamicArr* arr = CreateDynamicArray();

    AppendElement(arr, 200);
    AppendElement(arr, 300);
    AppendElement(arr, 400);
    AppendElement(arr, 500);
    AppendElement(arr, 600);

    RemoveElement(arr, 1);
    AppendElement(arr, 300);
    PrintArray(arr);
    InsertElement(arr, 1, 800);
    PrintArray(arr);
    ReplaceElement(arr, 1, 1000);
    PrintArray(arr);

    DeleteDynamicArray(arr);

}


