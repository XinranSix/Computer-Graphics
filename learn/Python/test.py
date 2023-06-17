import os

if __name__ == '__main__':
    with os.scandir('D:/workspace/otherCode') as entries:
        for entry in entries:
            # os.system('cd D:\workspace\otherCode\%s' % (entry.name))
            # os.system('git pull')
            os.system('pwd')
            os.system('cd ..')
