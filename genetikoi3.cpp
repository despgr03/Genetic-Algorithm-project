#include <iostream>
#include <list>
#include <array>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iterator>
#include <iomanip>

using namespace std;

//kanones
/*
0!=1,2,11
1!=2,3,10,11
2!=3,4,5,6
3!=6,8
4!=5
5!=6
6!=7,8
7!=8,9
8!=9,10
9!=10,12
10!=11,12
11!=12
12!=
*/

//mia synarthsh poy arxikopoiei thn lista opoy perierxei tis akolou8ies me ta xromata kai th 8esh ton xromaton.
//dexetai os orisma thn lista poy periexei pinakes tupou int 13 ueson opou se ka8e 8esh antistoixei sto meros tou grafhmatos , kai enan int k opou einai to plh8os,dhladh posous pinakes exei mesa h lista.
//ka8e 8esh ston pinaka exei enan ari8mo apo to ena mexri to 4 , osa kai ta xrommata.
void arxikopoihsh_plh8ous(list<array<int, 13>> &lista,int k){
    for(int j=0; j<k;j++){
        array<int, 13> pin;
        for(int i = 0; i < 13; i++) {
            int n = 0;
            while(n == 0) {//oste akoma kai an petuxei 0, na 3anampei sthn epanalhpsh
                n = rand() % 5; 
            }
            pin[i] = n;
        }
        lista.push_back(pin);
    }
}


//mia sunarthsh h opoia upologizei to pososto pou einai epituxhs mia akoou8ia analoga me ta sfalmata pou exei dia ta max sfalmata pou mporei na kanei
//dexetai os orismatata thn lista pou periexei mesa tis akolou8ies,mia lista onomati pososta opou ekei 8a ta apo8hkeusei ta pososta , enan double to sum1 opou 8a apo8hkeuetai to a8roisma ton pososton epituxias apo oles tis akolou8ies, enan double max opou 8a apo8hkeyei to megisto pososto epituxias, enan int deikth pou 8a apo8hkeuei th 8esh tou max kai mia lista pou apo8hkeyei ta posa la8h eixe ka8e dianysma
void ypologismos_posostou(list<array<int, 13>> lista, list<float> &pososta,double &sum1,double &max,int &deikths,list<int> &la8h){
    float per;
    sum1=0;
 for(int i=0;i<lista.size();i++){
    int sum=0;
    auto it = lista.begin();
    advance(it, i);
    if((*it)[0]==(*it)[1]){
        sum++;
    }
    if((*it)[0]==(*it)[2]){
        sum++;
    }
    if((*it)[0]==(*it)[11]){
        sum++;
    }
    if((*it)[1]==(*it)[2]){
        sum++;
    }
    if((*it)[1]==(*it)[3]){
        sum++;
    }
    if((*it)[1]==(*it)[10]){
        sum++;
    }
    if((*it)[1]==(*it)[11]){
        sum++;
    }
    if((*it)[2]==(*it)[3]){
        sum++;
    }
    if((*it)[2]==(*it)[4]){
        sum++;
    }
    if((*it)[2]==(*it)[5]){
        sum++;
    }
    if((*it)[2]==(*it)[6]){
        sum++;
    }
    if((*it)[3]==(*it)[6]){
        sum++;
    }
    if((*it)[3]==(*it)[8]){
        sum++;
    }
    if((*it)[4]==(*it)[5]){
        sum++;
    }
    if((*it)[5]==(*it)[6]){
        sum++;
    }
    if((*it)[6]==(*it)[7]){
        sum++;
    }
    if((*it)[6]==(*it)[8]){
        sum++;
    }
    if((*it)[7]==(*it)[8]){
        sum++;
    }
    if((*it)[7]==(*it)[9]){
        sum++;
    }
    if((*it)[8]==(*it)[9]){
        sum++;
    }
    if((*it)[8]==(*it)[10]){
        sum++;
    }
    if((*it)[9]==(*it)[10]){
        sum++;
    }
    if((*it)[9]==(*it)[12]){
        sum++;
    }
    if((*it)[10]==(*it)[11]){
        sum++;
    }
    if((*it)[10]==(*it)[12]){
        sum++;
    }
    if((*it)[11]==(*it)[12]){
        sum++;
    }
    la8h.push_back(sum);
	per=(26-sum)/26.0;

	if(per>max){
		max=per;
		deikths=i;
	}
    sum1+=per;
    cout<<"gia to "<<i<<". "<<per<<" % epituxia"<<endl;
    cout<<sum<<" sfalmata"<<endl;
    pososta.push_back(per);
 } 
 
}

//mia sunarthsh h opoia kanei th douleia tou troxou.ousiastika exei mia lista 8eseon oso 26-la8h tou ka8e dianusmatos epi ton ari8mo toy plu8hsmou kai analoga me to poso genetika kalos einai mia akolou8ia, dhladh oso pio megalo pososto epituxias exei, toses pio poles 8eseis 8a exei sthn lista.
//dexetai os orismata th lista me ta pososta epituxias ton akolou8ion, mia lista troxos h opoia 8a leitourgei san troxos kai 8a exei apo8hkeumenes tis 8eseis, enan double sum1 o opoios periexei to sunoliko a8roisma olon ton pososton epituxias ton akolou8ion kai mia lista pou periexei ta posa la8h eixe ka8e dianysma.
void arxikopoihsh_troxou(list<float> pososta,list<int> &troxos,double sum1,list<int> la8h){
	int j=0;
	for (auto& p : pososta) {
	p =p / sum1;//upologizei gia to ka8ena poso pososto tou troxou 8a pianei.auto ginetai an diairesoume to pososto epituxias tou ka8enos dia to sunoloki a8roisma epituxias olon
    cout <<"gia to "<<j<<" "<< p <<"% tou troxou"<< endl;
	j++;
	} 
	int i = 0;
    int metrhths = 0;
    for (const auto& l : la8h) {
		int count = 26-l;
        for (int k = 0; k < count; ++k) {
                troxos.push_back(metrhths);
                i++;  
        }
        metrhths++;
    }
}

//h sunarthsh auth pragmatopoiei th metala3h.
//dexetai os orismata th lista pou periexei mesa tis akolou8ies, kai enan float ari8mo k opou leei to pososto pou ginetai h metall3h.ean 8a ginei sto 10% 8a graftei os 10 
void metala3h(list<array<int,13>> &lista,float k){
	cout<<endl;
	int pl=lista.size();
	int n;
	int j;
	int per=((((k*pl)/100)+0.5)/1);//ypologizei poses metala3eis 8a ginoun analoga me to pososto kai to plh8os
	cout<<"metala3eis: "<<per<<endl;
	while(per!=0){
		n=rand()%lista.size();
		j=rand()%13;
		cout<<"to "<<n<<endl;
		auto it = next(lista.begin(),n);
		for (int elem : *it) {//emfanizei to prin ths metalla3hs
			cout << elem << " ";
		}
		while(true){//gia na e3asfalisoume oti h metala3h 8a ferei enan diaforetiko ari8mo apo auto pou eixe kai oti autos o ari8mos de 8a einai 0
			int m=rand() % 5;
			if((*it)[j]!=m & m!=0){
				(*it)[j] =m;
				break;
			}
		}
		cout << "metala3h: "<<endl;
		for (int elem : *it) {//kai to meta
			cout << elem << " ";
		}
		cout << endl;		
		per-=1;
	}
}


//h sunarthsh ayth pragmatopoiei thn merikh ananeosh, dhladh to pososto tou plh8hsmou pou 8a perasei opos einai sthn epomenh genia.
//dexetai os orismata thn lista me tous progonous, dhlafh tis akolou8ies, thn pista pou mpainoun oi apogonoi kai to pososto pou 8a gienei h merikh ananeosh.
void merikh_ananeosh(list<array<int,13>> lista, list<array<int,13>> &lista2,float k){
	int pl=lista.size();
	int n;
	int per=((((k*pl)/100)+0.5)/1);//ypologizei posoi progonoi 8a perasoun apeu8eias sthn epomenh genia analoga me to pososto kai to plh8os
	cout<<"merikh ananeosh: "<<per<<endl;
	list<int> tuxh;//periexei tous ari8mous ton akolou8ion pou exoun klhro8ei
	while(per!=0){
		bool flag=true;
		n=rand()%lista.size();
		for (auto& t : tuxh) {//elegxoume oste o tuxaios ari8mos pou parax8hke na mhn uparxei hdh
			if(t==n){
				flag=false;
			}
		}
		if(flag){
			cout<<"to "<<n<<endl;
			auto it = next(lista.begin(),n);
			for (int elem : *it) {
				cout << elem << " ";
			}
			lista2.push_back(*it);
			cout << endl;		
			per-=1;
			tuxh.push_back(n);
		}
	}
}


int main() {
	
    time_t t;
    srand((unsigned) time(&t));
    
    list<array<int, 13>> lista;
    list<float> pososta;
    //array<int,100> troxos;
	list<int>troxos;
    list<int>zeugaria;
    array<int,13> flag1;
    list<array<int,13>> lista2;
	list<int> la8h;
    int plh8os_listas_zeugaria;
	double sum1;
	float orio=0.88;//orio katallhlothtas
	double max;
	int deikths;
	int gen=3;
	
    arxikopoihsh_plh8ous(lista,15);
	
	max=0;
	cout << "oi apogonoi" << endl;
    for (const auto& arr : lista) { 
        for (const auto& num : arr) {  
            cout << num << " ";
        }
        cout << endl; 
    }
	
	
	while(gen!=0){
		lista2.clear();
		pososta.clear();
		zeugaria.clear();
		
		ypologismos_posostou(lista,pososta,sum1,max,deikths,la8h);
		
		if(max>=orio){
			auto it = lista.begin();
			auto it2=pososta.begin();
			advance(it, deikths);
			advance(it2,deikths);
			cout<<"to "<<deikths<<endl;
			for(int s=0; s<13; s++){
				cout<<(*it)[s]<<" ";
			}
			cout<<endl;
			cout<<(*it2)<<"% epituxia";
			break;
		}	
		 
		arxikopoihsh_troxou(pososta,troxos,sum1,la8h);

		int n;
		int f=0;
		merikh_ananeosh(lista,lista2,30);
		cout<<"zeugaria:"<<endl;
		int z=0;
		for(int i=0; i<lista.size()-lista2.size(); i++){
			auto it =troxos.begin();
			n=rand()%troxos.size();
			advance(it,n);
			n=(*it);
			zeugaria.push_back(n);
			if(z==0){
				cout<<"to "<<n;
				z++;
			}else{
				cout<<" me to "<<n<<endl;
				z=0;
			}
		}
		
		plh8os_listas_zeugaria=zeugaria.size();
		int indx=0;

		while (plh8os_listas_zeugaria >= 2) {
			auto it = lista.begin();
			auto it2 = lista.begin();
			auto z_it = zeugaria.begin();
			
			advance(z_it, indx);
			advance(it, *z_it);
			advance(z_it, 1);
			advance(it2, *z_it);

			array<int, 13> flag1;
			array<int, 13> flag2;

			for(int i = 0; i < 13; i++){
				if(i < 7){
					flag1[i] = (*it)[i];
					flag2[i] = (*it2)[i];

				} else {
					flag1[i] = (*it2)[i];
					flag2[i] = (*it)[i];

				}
			}
			
			lista2.push_back(flag1);
			lista2.push_back(flag2);
			indx += 2;
			plh8os_listas_zeugaria -= 2;
		}
		
		lista.clear();
		lista=lista2;
		
		metala3h(lista,10);
		
		cout << "oi apogonoi" << endl;
		for (const auto& arr : lista) { 
			for (const auto& num : arr) {  
				cout << num << " ";
			}
			cout << endl; 
		}
		gen--;
	}
	sum1=0.0;
	if(max<orio){
		ypologismos_posostou(lista,pososta,sum1,max,deikths,la8h);
		auto it = lista.begin();
		auto it2=pososta.begin();
		advance(it, deikths);
		advance(it2,deikths);
		cout<<"to "<<deikths<<endl;
		for(int s=0; s<13; s++){
			cout<<(*it)[s]<<" ";
		}
		cout<<endl;
		cout<<(*it2)<<"% epituxia";
	}
				
	return 0;
}