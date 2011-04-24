/******************************************************************************

  This source file is part of the MoleQueue project.

  Copyright 2011 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef QUEUELOCAL_H
#define QUEUELOCAL_H

#include "queue.h"

#include <QtCore/QProcess>

namespace MoleQueue {

/**
 * Queue for jobs to run locally.
 */

class QueueLocal : public Queue
{
  Q_OBJECT
public:
  explicit QueueLocal(QObject *parent = 0);
  ~QueueLocal();

public slots:
  /**
   * Submit a new job to the queue.
   * \param job The Program object to submit to the queue.
   * \return True on successful addition to the queue.
   */
  virtual bool submit(const Program &job);

protected slots:
  void finished(int exitCode, QProcess::ExitStatus exitStatus);

protected:
  /** Set up some default programs. */
  void setupPrograms();

  void runProgram();

  QProcess *m_process;
};

} // End namespace

#endif // QUEUELOCAL_H