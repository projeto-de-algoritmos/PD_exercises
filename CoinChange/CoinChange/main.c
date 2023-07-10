
#define min(a, b) (a < b ? a : b)

/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.


Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

*/

int coinChange(int* coins, int coinsSize, int amount)
{
    int max = amount + 1;
    int* m = (int*)malloc((amount + 1) * sizeof(int));
    for (int i = 0; i <= amount; i++)
    {
        m[i] = max;
    }
    m[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coinsSize; j++)
        {
            if (coins[j] <= i)
            {
                m[i] = min(m[i], 1 + m[i - coins[j]]);
            }
        }
    }

    int result = m[amount] > amount ? -1 : m[amount];
    free(m);
    return result;
}

int main()
{
    /*test1*/
    int coins[] = {1, 2, 5};
    int amount = 11;


    /*test2
    int coins[] = {2};
    int amount = 3;
*/
    /*test3
    int coins[] = {1};
    int amount = 0;
*/
    int coinsSize = sizeof(coins) / sizeof(int);

    int minCoins = coinChange(coins, coinsSize, amount);
    printf("%d\n", minCoins);
    return 0;
}
