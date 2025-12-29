class Solution {
public:
    long long minimumCost(int c1, int c2, int c3, int n1,
                          int n2) {
        long long int cost1=c1;
        long long int cost2=c2;
        long long int costBoth=c3;
        long long int need1=n1;
        long long int need2=n2;
        if (costBoth <= cost1 && costBoth <= cost2) {
             
            return (long long)(costBoth * max(need1, need2));
        } else {
            if (costBoth > cost1 + cost2) {
                return need1 * cost1 + need2 * cost2;
            } else {
                if (costBoth >= cost1 && costBoth >= cost2) {
                    if (need1 == need2) {
                        return costBoth * need1;
                    } else if (need1 > need2) {
                        return costBoth * need2 + cost1 * (need1 - need2);
                    } else if (need2 > need1) {
                        return costBoth * need1 + cost2 * (need2 - need1);
                    }
                }
                else if (costBoth > cost1 ) {
                    long long int sum = need2 * costBoth;
                    need1 -= need2;
                    if (need1 <= 0) {
                        return sum;
                    }
                    sum += (need1 * cost1);
                    return sum;

                } else if (costBoth > cost2) {
                    long long int sum = need1 * costBoth;
                    need2 -= need1;
                    if (need2 <= 0) {
                        return sum;
                    }
                    sum += (need2 * cost2);
                    return sum;
                }
            }
        }
        return 0;
    }
};