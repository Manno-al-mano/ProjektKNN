//
// Created by mpiot on 15.03.2022.
//

#ifndef NAI_PROJEKT1_TRAINER_H
#define NAI_PROJEKT1_TRAINER_H

/*
 * dodaje wartości ze stringa do wektora doubli
 * */
auto prepare(vector<double> & wektorDoubli, string& str){
    for (auto i=0;i<str.size();i++){
        if (str[i]==','){
            wektorDoubli.push_back(atof(str.substr(0,i).c_str()));
            str.erase(0,i+1);
            i=0;

        }
    }

}

/*
 * wyciąga z pliku testowego wektory
 * */
auto splitFileTest(const string &path, vector<vector<double>> & vectorTestowy){
    auto trainingfile = ifstream(path);
    auto wektorDoubli = vector<double>();
    for (auto str = string(); getline(trainingfile, str);){
        prepare(wektorDoubli, str);
        vectorTestowy.push_back(wektorDoubli);
        wektorDoubli.clear();

    }

}
/*
 * wyciąga nazwy i wektory z pliku treningowego
 * */
auto splitFileTrain(const string &path, vector<pair <string, vector<double>>> & vectorTreningowy){
    auto trainingfile = ifstream(path);
    //int iter=0;
    auto wektorDoubli = vector<double>();
    for (auto str = string(); getline(trainingfile, str);){
        prepare(wektorDoubli, str);
        vectorTreningowy.push_back(pair< string, vector<double> >(str,wektorDoubli));
        wektorDoubli.clear();

    }

}
#endif //NAI_PROJEKT1_TRAINER_H
