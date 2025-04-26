import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/daniel/Documentos/Project_ws/inter/install/inter_node'
