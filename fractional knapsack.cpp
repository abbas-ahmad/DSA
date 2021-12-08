/*
    Given weights and values of N items, we need to put these items in a knapsack of capacity W to
    get the maximum total value in the knapsack.
    Note: Unlike 0/1 knapsack, you are allowed to break the item. 
*/

static bool cmp(Item i1, Item i2){
        double pbw1 = (double) i1.value / i1.weight;
        double pbw2 = (double) i2.value / i2.weight;
        return pbw1 > pbw2;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr + n, cmp);
        
        double profit = 0;
        double capRem = W;
        
        for(int k = 0; k < n; k++){
            Item i = arr[k];
            if(capRem >= i.weight){
                profit += i.value;
                capRem -= i.weight;
            }
            else{
                double profitPerUnit =  (double) i.value / i.weight;
                profit += profitPerUnit * capRem;
                break;
            }
        }
        
        return profit;
    }