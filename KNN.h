//
// Created by mpiot on 16.03.2022.
//

#ifndef NAI_PROJEKT1_KNN_H
#define NAI_PROJEKT1_KNN_H
/*
 * Zwraca posortowaną tablicę wyników grupy treningowej do 1 wektora
 * */
auto kNNcalc(const vector<pair <string, vector<double>>> &vectorTreningowy,const vector<double> &vec){

    auto wyniki = vector<pair <string, double>>();

    double wynik=0;
    for(auto per:vectorTreningowy) {
        for (auto i = 0; i < per.second.size(); i++) {

            wynik+= pow(per.second[i]-vec[i],2);
        }
        wyniki.push_back(pair<string, double>(per.first,wynik));
        wynik=0;
    }
    sort(wyniki.begin(),
              wyniki.end(),
              [](pair<string, double> a, pair<string, double> b){return a.second<b.second;});

    return wyniki;
}

/*
* Zwraca k najmniejszych wyników kwadratu odległości wektorów
* */
auto kNNfindLowest(vector<pair <string, double>> & vec,  int k) {
    auto j = 0;
    auto n=0;

    for(auto i =0;i<vec.size()&&n<k;i++){

        if (vec[i].second>vec[j].second){
            n++;
        }
        j=i;
    }
    vec.resize(j);

}
/*
 * Zlicza wystąpienia każdej klasy
 * */
auto kNNcountOcc(const vector<pair <string, double>> &vectorWynikowy){
    auto liczydlo = vector<pair<string, int>>();
    for (auto per: vectorWynikowy) {
        auto found = false;
        for (auto i =0;i<liczydlo.size();i++) {
            if (liczydlo[i].first == per.first){
                found = true;
                liczydlo[i].second++;}
        }
        if (!found)
            liczydlo.push_back(pair < string, int > (per.first, 1));
    }

    sort(liczydlo.begin(),liczydlo.end(),[](pair<string, int> a, pair<string, int> b){return a.second>b.second;});
    return liczydlo;
}
/*
 * Zwraca nazwę klasy, która jest wynikiem i jej ilość wystąpień
 * */
auto kNNfindAnswer( const vector<pair <string, double>> &vectorWynikowy, const vector<pair<string, int>> &liczydlo){
    if(liczydlo.size()<2||(liczydlo[0].second>liczydlo[1].second)){
    return liczydlo[0];
}
    else{
        double dist=0;
        double min=NULL;
        int minIndex;
        for(auto i=0;i<liczydlo.size();i++){
            for(auto per:vectorWynikowy){
                if (per.first==liczydlo[i].first){
                    dist=dist+per.second;
                }
            }
            if((min==NULL||min>dist)&&liczydlo[i].second==liczydlo[0].second){
                min = dist;
                minIndex=i;
            }
            dist=0;
        }
        return liczydlo[minIndex];
}

}
/*
 * wylicza kNN i wyświetla wynik
 * */
auto kNN(const vector<pair <string, vector<double>>> &vectorTreningowy,const vector<double> &vec, int k){
  auto vectorWynikowy = kNNcalc(vectorTreningowy, vec);
  kNNfindLowest(vectorWynikowy,k);
 auto licznik = kNNfindAnswer(vectorWynikowy,kNNcountOcc(vectorWynikowy));
 printVector(vec);
 auto acc = ((double)licznik.second/vectorWynikowy.size())*100;
 cout<<licznik.first<<" "<<acc<<"% Accuracy\n";
}

#endif //NAI_PROJEKT1_KNN_H
