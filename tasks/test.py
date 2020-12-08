import threading
import time


def do_stuff():
    t = threading.current_thread()
    while getattr(t, "doRun", True):
        with open("log.txt", "a") as f:
            print("Thread still runs!", file=f)
        time.sleep(1)


t = threading.Thread(target=do_stuff, daemon=True)
t.start()
time.sleep(10)
t.doRun = False
t.join()

