class FizzBuzz {
    private int n;
    Semaphore s0, s1, s2, s3;
     private Semaphore sFizz, sBuzz, sFizzBuzz, sNumber;


    public FizzBuzz(int n) {
        this.n = n;
         sFizz = new Semaphore(0);      // Start with 0 so fizz waits until it's needed
        sBuzz = new Semaphore(0);      // Same for buzz
        sFizzBuzz = new Semaphore(0);  // Same for fizzbuzz
        sNumber = new Semaphore(1); 
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
       for(int i=1;i<=n;i++){
         if(i%3==0 && i%5!=0){
            sFizz.acquire();
            printFizz.run();
            release(i+1);
         }
       }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
         for(int i=1;i<=n;i++){
            if(i%5==0 && i%3!=0){
                sBuzz.acquire();
                printBuzz.run();
                release(i+1);
            }
         }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0){
                sFizzBuzz.acquire();
                printFizzBuzz.run();
                release(i+1);

            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
         for(int i=1;i<=n;i++){
            if(i%3!=0 && i%5!=0){
               sNumber.acquire();
                printNumber.accept(i);
                release(i+1);

            }
        }
    }
    public void release(int num){
        if(num>n){
            return;
        }
        if(num%15 ==0){
            sFizzBuzz.release();
        }
        else if(num%3==0 && num%5!=0){
            sFizz.release();
        }
        else if(num%5==0 && num%3!=0){
            sBuzz.release();
        }
        else{
            sNumber.release();
        }
    }
}