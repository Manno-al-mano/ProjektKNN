/*
//
// Created by mpiot on 15.03.2022.
//




#ifndef NAI_PROJEKT1_APPKERNEL_H
#define NAI_PROJEKT1_APPKERNEL_H

*/
/*
 * liczy kNN dla grupy wektorów
 * *//*

auto testGroup(const vector<pair <string, vector<double>>> &vectorTreningowy,
               const vector<vector<double>> &vectorTestowy,
               int k
               )
{
    for(auto vec:vectorTestowy){
        kNN(vectorTreningowy,vec,k);
    }
}
*/
/*
 * pozwala na podanie wymiarów wektora i policzenie jego kNN
 * *//*

auto addVector(int k, const vector<pair <string, vector<double>>> &vectorTreningowy){
    string str;
    auto write=true;
    auto vec = vector<double>();
    cout<< "Podaj wymiary wektora lub napisz \"exit\" aby wyjsc\n";
    while (write){

        cin>>str;
        if(str=="exit"){
            write= false;
        }
        else {
            vec.push_back(atof(str.c_str()));
            if (vec.size()==vectorTreningowy[0].second.size()){
                kNN(vectorTreningowy, vec, k);
            vec.clear();
                cout<< "Podaj wymiary wektora lub napisz \"exit\" aby wyjsc\n";
            }
        }


    }
}
*/
/*
 * wywołuje wszystkie funkcje
 * *//*

auto AppKernel(int argc, char *argv[]) {
    auto stringi = vector<string>();
    stringi=string_conv(argc,argv);
    if (!validateAll(stringi)){
        cout<<"Podano niewłaściwe Flagi"<<"\n";
        return 0;}
    auto vectorTreningowy = vector<pair <string, vector<double>>>();
    splitFileTrain(stringi[1], vectorTreningowy);
auto vectorTestowy = vector<vector<double>>();
    splitFileTest(stringi[2], vectorTestowy);
    int k = stoi(stringi[0]);
   testGroup(vectorTreningowy,vectorTestowy, k);
   addVector(k,vectorTreningowy);






}
#endif //NAI_PROJEKT1_APPKERNEL_H
*/
