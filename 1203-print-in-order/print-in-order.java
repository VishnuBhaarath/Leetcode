class Foo {
    Semaphore one,two,three;
    public Foo() {
        one=new Semaphore(1);
        two=new Semaphore(0);
        three=new Semaphore(0);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        one.acquire();
        printFirst.run();
        two.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        two.acquire();
        printSecond.run();
        three.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        three.acquire();
        printThird.run();
    }
}