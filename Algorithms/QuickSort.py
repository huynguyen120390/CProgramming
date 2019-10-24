def partition1(arr):
    #LOW MEETS HIGH
    #pivot is first element
    #low start at 0 at the hole, high at len(arr) move first
    pivot = arr[0]
    l= 0
    h = len(arr) -1 


def partition2(arr,low,high):
    #CHASE TO PIVOT AT THE END
    #low, loop indices chase till meet pivot at the end
    #assume high is just right before pivot
    print("Partition ",low,high,arr[low:high+1],arr)
    l = low - 1
    pivot = arr[high]
    for loop in range(low,high,1):
        # Try to move low element to front, no matter how low the arr[low] is
        
        if(arr[loop] <= pivot):
            print("Swap")
            l += 1
            arr[l],arr[loop] = arr[loop],arr[l] 
        print(l,loop,high,arr[low:high+1],arr)
    
    # Low elements are at front now , so low + 1 is the middle point where the pivot should stand
    # This point is sorted
    # Swap pivot and the arr[low+1]
    arr[low + 1] , arr[high] = arr[high],arr[low+1]
    

    return low + 1

def quicksort(arr,low,high):
    if high - low > 2:
        s = partition2(arr,low,high)
        quicksort(arr,low,s)
        quicksort(arr,s+1,high)

if __name__ == "__main__":
    arr = [10,5,6,4,7,1,8,3]
    quicksort(arr,0,len(arr)-1)
    print(arr)





        
    
    
            

