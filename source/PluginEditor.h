#pragma once
#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include <cmath>
#include "PluginProcessor.h"

class GridPanel : public Component
{
public:
	GridPanel();
	~GridPanel();

	void paint(Graphics&) override;
	Point<float> centre() { return Point<float>(getWidth() / 2.f, getHeight() / 2.f); }

	double sourceAzimuth = 0.;
private:
	Image headIcon;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GridPanel)
};

class HrtfBiAuralAudioProcessorEditor : public AudioProcessorEditor,
	private Slider::Listener,
	private ComboBox::Listener
{
public:
	HrtfBiAuralAudioProcessorEditor(HrtfBiAuralAudioProcessor&);
	~HrtfBiAuralAudioProcessorEditor();

	void paint(Graphics&) override;
	void resized() override;
	void mouseDrag(const MouseEvent&) override;
	void sliderValueChanged(Slider*) override;
	void comboBoxChanged(ComboBox*) override;

private:
	void updateHrir();

	HrtfBiAuralAudioProcessor& processor;
	ComboBox hrtfList;
	GridPanel grid;
	Slider elevationSlider;
	Slider crossoverSlider;
	double azimuth = 0.;
	double elevation = 0.;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HrtfBiAuralAudioProcessorEditor)
};

#endif
