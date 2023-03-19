#include <iostream>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<chrono>
using namespace std;
int *mergeS = new int[100000000];
int *countS = new int[100000000];
int *shellS = new int[100000000];
int *selectionS = new int[100000000];
int *radixS = new int[100000000];
int *radixS2 = new int[100000000];
int *radixS3 = new int[100000000];
int *introS = new int[100000000];
int *v2 = new int[100000000];
void interclasare(int v[], int st, int mij, int dr)
{
    int i=st, j=mij+1, k=st;

    while(i <= mij && j <= dr){
        if(v[i] <= v[j]){
            v2[k] = v[i];
            i++;
        }
        else{
            v2[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= mij) {
        v2[k] = v[i];
        i++;
        k++;
    }

    while (j <= dr) {
        v2[k] = v[j];
        j++;
        k++;
    }
    for(int i=st; i<k; i++)
        v[i] = v2[i];
}

void mergeSort(int v[], int st, int dr)
{
    int mij;
    if(st < dr){
        mij = (st+dr)/2;
        mergeSort(v, st, mij);
        mergeSort(v, mij+1, dr);
        interclasare(v, st, mij, dr);
    }

}

void shellSort(int v[], int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int aux = v[i];
            int j;
            for (j = i; j >= interval && v[j - interval] > aux; j -= interval)
                v[j] = v[j - interval];
            v[j] = aux;
        }
    }
}

void countSort(int v[], int n)
{
    int maxim = 0;
    for(int i=0; i<n; i++)
        if(v[i] > maxim)
            maxim = v[i];

    int *a = new int[maxim+1];
    for(int i=0; i<=maxim; i++)
        a[i] = 0;

    for(int i=0; i<n; i++)
        a[v[i]]++;

    int* aux = new int[n];
    int k=0;
    for(int i=0; i<=maxim; i++)
        for(int j=1; j<=a[i]; j++)
            aux[k++] = i;

    for(int i=0; i<n; i++)
        v[i] = aux[i];

    if(a != NULL){
        delete[] a;
        a = NULL;
    }
    if(aux != NULL){
        delete[] aux;
        aux = NULL;
    }
}

void selectionSort(int v[], int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(v[i] > v[j])
                swap(v[i], v[j]);
}

void radixSort(int v[], int n)
{
    int nrmax=0;
    for(int i=0; i<n; i++){
        int nr=0, x=v[i];
        while(x){
            nr++;
            x/=10;
        }
        if(nr > nrmax)
            nrmax = nr;
    }
    int p=10, q=1;

    for(int j=1; j<=nrmax; j++){

        int* c = new int[10], *aux = new int[n];
        for(int i=0; i<10; i++)
            c[i] = 0;

        for(int i=0; i<n; i++)
            c[v[i]%p/q]++;
        c[0]--;

        for(int i=1; i<10; i++)
            c[i] += c[i-1];

        for(int i=n-1; i>=0; i--){
            aux[c[v[i]%p/q]] = v[i];
            c[v[i]%p/q]--;
        }

        for(int i=0; i<n; i++)
            v[i] = aux[i];

        p*=10;
        q*=10;

        if(c != NULL){
            delete[] c;
            c = NULL;
        }
        if(aux != NULL){
            delete[] aux;
            aux = NULL;
        }
    }
}

void radixSort2(int v[], int n, int baza)
{

    int x = baza, p=0;
    while(x != 1){
        p++;
        x = x>>1;
        }

    int nrmax=0;
    for(int i=0; i<n; i++){
        int nr=0, x=v[i];
        while(x){
            nr++;
            x = x>>p;
        }
        if(nr > nrmax)
            nrmax = nr;
    }

    int q=0;

    for(int j=1; j<=nrmax; j++){

        int *c = new int[baza], *aux = new int[n];
        for(int i=0; i<baza; i++)
            c[i] = 0;

        for(int i=0; i<n; i++)
            c[v[i]>>q & (baza-1)]++;
        c[0]--;

        for(int i=1; i<baza; i++)
            c[i] += c[i-1];

        for(int i=n-1; i>=0; i--){
            aux[c[v[i]>>q & (baza-1)]] = v[i];
            c[v[i]>>q & (baza-1)]--;
        }

        for(int i=0; i<n; i++)
            v[i] = aux[i];

        q+= p;

        if(c != NULL){
            delete[] c;
            c = NULL;
        }
        if(aux != NULL){
            delete[] aux;
            aux = NULL;
        }
    }
}

bool verifSortare(int a[], int n)
{
    for(int i=0; i<n; i++)
        if(a[i] != introS[i])
            return false;
    return true;
}

int main()
{
    ifstream f("numere.txt");
    ofstream g("sortate.txt");
    int n, numarTeste, nmax;
    f>>numarTeste;
    for(int i=0; i<numarTeste; i++){
        g<<"Testul "<<i+1<<":"<<endl;
        f>>n>>nmax;
        g<<"N = "<<n<<"   "<<"Max = "<<nmax<<endl<<endl;
        for(int i=0; i<n; i++){
            f>>mergeS[i];
            shellS[i] = mergeS[i];
            countS[i] = mergeS[i];
            selectionS[i] = mergeS[i];
            radixS[i] = mergeS[i];
            radixS2[i] = mergeS[i];
            radixS3[i] = mergeS[i];
            introS[i] = mergeS[i];
        }

        g<<"INTROSORT"<<endl;
        auto start6 = chrono::steady_clock::now();
        sort(introS, introS + n);
        auto end6 = chrono::steady_clock::now();
        g<<verifSortare(introS, n)<<endl;
        g << "Timpul sortarii:  "
        << chrono::duration_cast<chrono::microseconds>(end6 - start6).count()
        << " µs" << endl<<endl;

        if(n <= 100000){
            g<<"SELECTIONSORT"<<endl;
            auto start = chrono::steady_clock::now();
            selectionSort(selectionS, n);
            auto end = chrono::steady_clock::now();
            g<<verifSortare(selectionS, n)<<endl;
            g << "Timpul sortarii:  "
            << chrono::duration_cast<chrono::microseconds>(end - start).count()
            << " µs" << endl<<endl;
        }

        g<<"RADIXSORT BAZA 65536"<<endl;
        auto start = chrono::steady_clock::now();
        radixSort2(radixS2, n, 65536);
        auto end = chrono::steady_clock::now();
        g<<verifSortare(radixS2, n)<<endl;
        g << "Timpul sortarii:  "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl<<endl;

        g<<"RADIXSORT BAZA 16"<<endl;
        auto start7 = chrono::steady_clock::now();
        radixSort2(radixS3, n, 16);
        auto end7 = chrono::steady_clock::now();
        g<<verifSortare(radixS3, n)<<endl;
        g << "Timpul sortarii:  "
        << chrono::duration_cast<chrono::microseconds>(end7 - start7).count()
        << " µs" << endl<<endl;

        g<<"RADIXSORT BAZA 10"<<endl;
        auto start2 = chrono::steady_clock::now();
        radixSort(radixS, n);
        auto end2 = chrono::steady_clock::now();
        g<<verifSortare(radixS, n)<<endl;
        g << "Timpul sortarii:  "
        << chrono::duration_cast<chrono::microseconds>(end2 - start2).count()
        << " µs" << endl <<endl;

        g<<"MERGESORT"<<endl;
        auto start3 = chrono::steady_clock::now();
        mergeSort(mergeS, 0, n-1);
        auto end3 = chrono::steady_clock::now();
        g<<verifSortare(mergeS, n)<<endl;
        g << "Timpul sortarii:  "
        << chrono::duration_cast<chrono::microseconds>(end3 - start3).count()
        << " µs" << endl <<endl;

        g<<"SHELLSORT"<<endl;
        auto start4= chrono::steady_clock::now();
        shellSort(shellS, n);
        auto end4 = chrono::steady_clock::now();
        g<<verifSortare(shellS, n)<<endl;
        g << "Timpul sortarii:  "
        << chrono::duration_cast<chrono::microseconds>(end4 - start4).count()
        << " µs" << endl<<endl;

        g<<"COUNTSORT"<<endl;
        auto start5 = chrono::steady_clock::now();
        countSort(countS, n);
        auto end5 = chrono::steady_clock::now();
        g<<verifSortare(countS, n)<<endl;
        g << "Timpul sortarii:  "
        << chrono::duration_cast<chrono::microseconds>(end5 - start5).count()
        << " µs" << endl<<endl;
    }
    return 0;
}

