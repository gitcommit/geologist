import sys

class Class(object):
    def __init__(self, name):
        self.name = name
    def includeGuardName(self):
        return '{}_H'.format(self.name)
    def headerFileName(self):
        return '{}.h'.format(self.name)
    def implementationFileName(self):
        return '{}.cpp'.format(self.name)
    def createHeader(self):
        h = ['#ifndef {}'.format(self.includeGuardName()),
             '#define {}'.format(self.includeGuardName()),
             '',
             '#include <QtCore/QObject>',
             '',
             'class {}: public QObject {{'.format(self.name),
             '\tQ_OBJECT',
             'public:',
             '\t{}(QObject* p = 0);'.format(self.name),
             '\tvirtual ~{}();'.format(self.name),
             'protected:',
             'private:',
             '};',
             '',
             '#endif']
        return h;
    def createImplementation(self):
        i = ['#include "{}"'.format(self.headerFileName()),
             '',
             '{cn}::{cn}(QObject* p)'.format(cn=self.name),
             '\t:QObject(p)',
             '{}',
             '',
             '{cn}::~{cn}()'.format(cn=self.name),
             '{}',
             '']
        return i
if '__main__' == __name__:
    if len(sys.argv) != 2:
        print('usage: classgen.py NewClass')
        sys.exit(-1)
    c = Class(sys.argv[1])
    print("class: ",c.name)
    hf = open(c.headerFileName(), 'w')
    hf.write('\n'.join(c.createHeader()))
    hf.write('\n');
    hf.close()

    imp = open(c.implementationFileName(), 'w');
    imp.write('\n'.join(c.createImplementation()))
    imp.write('\n');
    imp.close()

    sys.exit(0)
