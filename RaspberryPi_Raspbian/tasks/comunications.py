# -*- coding: utf-8 -*-
__author__ = 'toopazo'


import multiprocessing
import logging
logger = logging.getLogger(__name__)


def task_comunications():
    arg = "name %s, pid %s, is_alive %s, exitcode %s" %\
          (taskHandler.name, taskHandler.pid, taskHandler.is_alive(), taskHandler.exitcode)
    logger.debug(arg)

    while True:
        pass

taskHandler = multiprocessing.Process(group=None,
                                      target=task_comunications,
                                      name="task_comunications",
                                      args=(),
                                      kwargs={})