#include <iostream>

template<class T>
void ordenarInsercion(T v[],int a,int b){
  for(int i = a; i<=b; i++){
    int key = v[i];
    int j = i - 1;

    while(j>=a-1&&v[j]>key){
      v[j+1] = v[j];
      j = j - 1;
    }

    v[j+1] = key;
  }
}

template<class T>
void particion2(T v[], int a, int b, T pivote, int& p, int& q){
  int k;
  T aux;
  p = a;
  k = a;
  q = b;

  while(k<=q){
    if(v[k] == pivote){
      k = k+1;
    }
    else if(v[k] < pivote){
      aux = v[p];
      v[p] = v[k];
      v[k] = aux;
      p = p+1;
      k = k+1;
    }
    else{
      aux = v[q];
      v[q] = v[k];
      v[k] = aux;
      q = q-1;
    }
  }
}

template<class T>
T seleccion2(T v[], int a, int b, int k){
  int l, p, q, s, pm, t;
  T aux,mm;
  t = b-a+1;
  if (t<=12){
    ordenarInsercion<int>(v,a,b);
    return v[k];
  }
  else{
    s = t/5;
    for(l=1;l<=s;l++){
      ordenarInsercion<int>(v,a+5*(l-1),a+5*l-1);
      pm = a+5*(l-1)+(5/2);
      aux = v[a+1-l];
      v[a+l-1] = v[pm];
      v[pm] = aux;
    }
    mm = seleccion2(v,a,a+s-l,a+(s-1)/2);
    particion2<int>(v,a,b,mm,p,q);
    if((k>=p)&&(k<=q)){
      return mm;
    }
    else if (k<p){
      return seleccion2(v,a,p-1,k);
    }
    else{
      return seleccion2(v,q+1,b,k);
    }
  }
}

int main() {
  const int n = 13;
  //1,4,7,8,9,11,17,23,29,45,47,61,99
  int v[n] = {4,8,11,23,45,61,7,9,1,17,29,47,99};
  std::cout << seleccion2<int>(v,0,n-1,4);
}