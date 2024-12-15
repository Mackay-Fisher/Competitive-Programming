//We can store sparse vectors in form of index-value pair for the non zero elements:

// For example [0,0,4.5,0,0,0,3.0,2.5,0] can be stored as [(7,2.5), (6,3.0), (2,4.5)]

// Could you design the data structure to store the sparse vectors and the library routines for addition and multiplication between two sparse vectors in the format we mentioned?

// Followup question what about 3 sparse vectors and combiantrion of multiply and add (A*B + C)

// Vector mul_and_add(Vector v1, Vector v2, Vector v3)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class VectorSP{

    public:
    VectorSP(vector<std::pair<int, double>> elements = {}) {
        sort(elements.begin(),elements.end());
        Vectorsp = elements;
    }

    static VectorSP add(VectorSP A, VectorSP B){
        VectorSP result;
        int i=0,j=0;
        while(i<A.Vectorsp.size() && j<B.Vectorsp.size()){
            double sum = 0;
            if(A.Vectorsp[i].first == B.Vectorsp[j].first){
                sum = A.Vectorsp[i].second + B.Vectorsp[j].second;
                result.Vectorsp.push_back({A.Vectorsp[i].first,sum});
                i++;
                j++;
            }else if(A.Vectorsp[i].first < B.Vectorsp[j].first){
                sum = A.Vectorsp[i].second;
                result.Vectorsp.push_back({A.Vectorsp[i].first,sum});
                i++;
            }else{
                sum = B.Vectorsp[j].second;
                result.Vectorsp.push_back({B.Vectorsp[j].first,sum});
                j++;
            }
        }

        //Add the remianing A values
        while (i<A.Vectorsp.size())
        {
            result.Vectorsp.push_back({A.Vectorsp[i].first,A.Vectorsp[i].second});
            i++;
        }
        
        //Add the remining B values
        while (j<B.Vectorsp.size())
        {
            result.Vectorsp.push_back({B.Vectorsp[j].first,B.Vectorsp[j].second});
            j++;
        }

        return result;
    }

    static VectorSP mult(VectorSP A, VectorSP B){
        VectorSP result;
        int i=0,j=0;
        while(i<A.Vectorsp.size() && j<B.Vectorsp.size()){
            double mul = 0;
            if(A.Vectorsp[i].first == B.Vectorsp[j].first){
                mul = A.Vectorsp[i].second * B.Vectorsp[j].second;
                result.Vectorsp.push_back({A.Vectorsp[i].first,mul});
                i++;
                j++;
            }else if(A.Vectorsp[i].first < B.Vectorsp[j].first){
                i++;
            }else{
                j++;
            }
        }
        return result;

    }

    static VectorSP mult_add(VectorSP A, VectorSP B, VectorSP C){
        return add(mult(A,B),C);
    }

    void print(){
        for(auto p : Vectorsp){
            cout<<"("<<p.first<<","<<p.second<<")"<<endl;
        }
        cout<<endl;
    }

    private:
        vector<pair<int,double>> Vectorsp;
};



int main(){
    VectorSP v1({{3, 1.0}, {2, 2.0}, {7, 3.5}});
    VectorSP v2({{2, 4.0}, {6, 2.0}, {5, 3.5}});
    VectorSP v3({{1, 1.0}, {6, 2.0}, {2, 3.5}});
    // v1.print();
    // v2.print();
    // VectorSP res = VectorSP::add(v1,v2);
    // VectorSP res2 = VectorSP::mult(v1,v2);
    VectorSP::mult_add(v1,v2,v3).print();
    // res.print();
    // res2.print();
    
    // v3.print();
}