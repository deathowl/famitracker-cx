#ifndef _ALSA_HPP_
#define _ALSA_HPP_

#include <alsa/asoundlib.h>
#include "core/soundsink.hpp"
#include "core/soundthread.hpp"

typedef core::SoundSink core_api_SoundSink;

extern "C" core_api_SoundSink * sound_create();

class AlsaSound : public core::SoundSinkPlayback
{
public:
	AlsaSound();
	~AlsaSound();
	void initialize(unsigned int sampleRate, unsigned int channels, unsigned int latency_ms);
	void close();
	void setPlaying(bool playing);

	int sampleRate() const;
private:
	static void callback(void *);
	snd_pcm_t * m_handle;
	snd_pcm_uframes_t m_buffer_size, m_period_size;
	int m_sampleRate;
	core::SoundThread m_thread;
	volatile bool m_running;
};

#endif

