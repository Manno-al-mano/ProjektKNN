//
// Created by s22222 on 2022-04-05.
//

#ifndef NAI_PROJEKT1_PERCEPTRON_H
#define NAI_PROJEKT1_PERCEPTRON_H
class Perceptron{
    auto alfa=0.01;
    auto próg=0.5;
    vector<double> vec;
    string nazwa;
    Perceptron(const vector<double>& vec,const string& nazwa){
        this.vec=vec;
        this.nazwa=nazwa;
    }

    auto train(bool expectedValue,const vector<double >&sprawdzany){
        auto skalar=0;
        for(auto i = 0; i<sprawdzany.size();i++){
            skalar+=sprawdzany[0]*vec[0]
        }
     auto poprawnosc=skalar>próg;
        if(expectedValue!=poprawnosc){
            for(auto i = 0; i<sprawdzany.size();i++){
                vec[i]=vec[i]+(expectedValue-poprawnosc)*alfa*sprawdzany[i];
            }
        }
    }

};
#endif //NAI_PROJEKT1_PERCEPTRON_H
