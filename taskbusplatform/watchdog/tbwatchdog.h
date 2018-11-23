/*!
 * Watchdog for memory size monitor.
  @author goldenhawking@163.com
  @date 2016-09-12
*/
#ifndef TBWATCHDOG_H
#define TBWATCHDOG_H

#include <QAbstractTableModel>
#include <QMap>
#include <QVector>
#include <QProcess>
#include <QMutex>
#include "../core/taskproject.h"
#include "../core/process_prctl.h"
class tbWatchDog
{
public:
	tbWatchDog();
	void watch(QProcess * proc = nullptr);
	void update_table();
	QVector<TASKBUS::tagMemoryInfo> get_info();
private:
	QMap<qint64, TASKBUS::tagMemoryInfo> m_map_pid;
	QMutex m_mutex;
};

tbWatchDog & tb_watch_dog();

#endif // TBWATCHDOG_H
