import os

from ai_flow import AIFlowMaster

if __name__ == '__main__':
    master = AIFlowMaster(os.path.dirname(os.path.abspath(__file__)) + '/master.yaml')
    master.start(is_block=True)
