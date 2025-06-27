#include<iostream>
#include<random>

// std::uniform_int_distributionを利用した一様乱数生成クラス
class Random_Gen{
    std::random_device seed_gen;
    std::mt19937 engine;
    std::uniform_int_distribution<int64_t> dist;
    public:
        // Constructor [l,r]で生成する値の範囲を指定
        Random_Gen() : engine(seed_gen()) {}
        Random_Gen(int64_t l, int64_t r) : engine(seed_gen()), dist(l,r) {}
        
        // 現在の生成する値の範囲をstd::pairで返す
        std::pair<int64_t,int64_t> get_range(){
            return std::make_pair(dist.min(),dist.max());
        }
        // 生成する値の範囲を[l,r]に変更する
        void set_range(int64_t l, int64_t r){
            std::uniform_int_distribution<int64_t>::param_type Param(l,r);
            dist.param(Param);
        }
        // [l,r]内の一様分布の整数を返す
        int64_t gen(){
            return dist(engine);
        }
        int64_t operator()(){ return gen(); }
};

int get_die(){
    Random_Gen die(1,6);
    return die.gen();
}

int main(){
    int die1,die2;
    die1=get_die();
    die2=get_die();
    int sum_dice=die1+die2;

    std::cout<<"Rolling dice...\n";
    std::cout<<"Die 1: "<<die1<<"\n";
    std::cout<<"Die 2: "<<die2<<"\n";
    std::cout<<"Total value: "<<sum_dice<<"\n";
}