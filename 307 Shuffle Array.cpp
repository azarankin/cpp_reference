

#include <vector>
#include <utility> 

void shuffleArray(std::vector<int>& arr)
{
    std::srand(static_cast<unsigned>(std::time(0))); // אתחול הגרלה
    int n = (int)arr.size();

    for (int i = n - 1; i > 0; --i)
    {
        int j = std::rand() % (i + 1); // j =  0 > i
        std::swap(arr[i], arr[j]);    // replace the next place with the random number
    }
}



