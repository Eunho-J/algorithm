#include <iostream>

#define AND_MASK(num_bits) ((~(uint64_t)0) % ((uint64_t)1<<num_bits))

using namespace std;

uint64_t get_complement_of_two(uint64_t n)
{
    return ~n + 1;
}

uint64_t get_min_ones(uint64_t distance, uint64_t num_shift)
{
    uint64_t count = 0, count_comp = 1;

    for (uint64_t tmp = distance; tmp != 0; count++)
        tmp &= (tmp-1);
    
    for (uint64_t tmp = AND_MASK((num_shift-1)) & get_complement_of_two(distance); tmp != 0; count_comp++)
        tmp &= (tmp-1);
    
    return min(count, count_comp);
}

int main(int argc, char const *argv[])
{
    uint64_t start = 0, target = 0, result = 0, num_shift_big = 0, num_shift_small = 0,
            closest_big = 0, closest_small = 0, distance_big = 0, distance_small = 0,
            result_big = 0, result_small = 0;
    
    cin >> start >> target;

    if (start >= target)
    {
        result = start - target;
    }
    else
    {   
        if (start == 0)
        {
            start+=1;
            result+=1;
        }
        closest_big = start;
        while (closest_big < target)
        {
            closest_big = closest_big << 1;
            num_shift_big += 1;
        }
        
        num_shift_small = num_shift_big - 1;
        closest_small = closest_big >> 1;
        distance_big = closest_big - target;
        distance_small = target - closest_small;

        // big to target
        result_big = distance_big / ( ((uint64_t)1) << num_shift_big );
        distance_big = distance_big % ( ((uint64_t)1) << num_shift_big );
        result_big += get_min_ones(distance_big, num_shift_big);

        // small to target
        result_small = distance_small / ( ((uint64_t)1) << num_shift_small );
        distance_small = distance_small % ( ((uint64_t)1) << num_shift_small );
        result_small += get_min_ones(distance_small, num_shift_small);
        
        result += min(result_big, result_small);
    }

    cout << result << endl;
    
    return 0;
}
