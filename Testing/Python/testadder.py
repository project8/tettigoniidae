"""
  testadder.py
 
   Created on: Jun 14, 2022
       Author: F. Thomas
"""

__all__ = []

import _nymph
import scarab

def main(args):
    
    testadder = _nymph.processor.get_processor('adder', 'name')
    
    param = scarab.ParamValue( 1.0 )
    param_node = scarab.ParamNode()
    param_node.add('x', param)
    
    testadder.configure(param_node)
    
    print(testadder.x)
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
