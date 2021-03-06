#ifndef LEVELMETER_H
#define LEVELMETER_H

#include <QWidget>
#include <QTime>
#include <QTimer>

class LevelMeter : public QWidget
{
    Q_OBJECT

public:

    explicit LevelMeter(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    virtual QSize sizeHint() const override;

public slots:

    void reset();
    void levelChanged(qreal rmsLevel, qreal peakLevel, int numSamples);

private slots:

    void redrawTimerExpired();

private:
    /**
     * Height of RMS level bar.
     * Range 0.0 - 1.0.
     */
    qreal m_rmsLevel;

    /**
     * Most recent peak level.
     * Range 0.0 - 1.0.
     */
    qreal m_peakLevel;

    /**
     * Height of peak level bar.
     * This is calculated by decaying m_peakLevel depending on the
     * elapsed time since m_peakLevelChanged, and the value of m_decayRate.
     */
    qreal m_decayedPeakLevel;

    /**
     * Time at which m_peakLevel was last changed.
     */
    QTime m_peakLevelChanged;

    /**
     * Rate at which peak level bar decays.
     * Expressed in level units / millisecond.
     */
    qreal m_peakDecayRate;

    /**
     * High watermark of peak level.
     * Range 0.0 - 1.0.
     */
    qreal m_peakHoldLevel;

    /**
     * Time at which m_peakHoldLevel was last changed.
     */
    QTime m_peakHoldLevelChanged;

    QTimer *m_redrawTimer;

    QColor m_rmsColor;
    QColor m_peakColor;

};

#endif // LEVELMETER_H
