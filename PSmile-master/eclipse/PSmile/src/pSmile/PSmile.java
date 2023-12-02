/**
 * Smile detection library for Processing 2.0.
 *
 * ##copyright##
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author		Bryan Chung
 * @modified	21-09-2012
 * @version		1.1.0
 */

package pSmile;

import processing.core.PApplet;
import processing.core.PConstants;
import processing.core.PImage;

/**
 * This is a template class and can be used to start a new processing library or
 * tool. Make sure you rename this class as well as the name of the example
 * package 'template' to your own library or tool naming convention.
 * 
 * @example Hello
 * 
 *          (the tag @example followed by the name of an example included in
 *          folder 'examples' will automatically include the example in the
 *          javadoc.)
 * 
 */

public class PSmile implements PConstants {

	static {
		if (isMac()) {
			System.loadLibrary("PSmile");
		} else if (isWindows()) {
			if (is32Bit()) {
				System.loadLibrary("PSmile32");
			} else if (is64Bit()) {
				System.loadLibrary("PSmile64");
			}
		}
	}

	private PApplet parent;
	private int w;
	private int h;

	public final static String VERSION = "1.1.0";

	/**
	 * a Constructor, usually called in the setup() method in your sketch to
	 * initialize and start the library.
	 * 
	 */
	public PSmile(PApplet _p, int _w, int _h) {
		parent = _p;
		w = _w;
		h = _h;
		init(w, h);
		welcome();
	}

	private native void init(int _w, int _h);

	public native float findSmile(float[] _i, int _w, int _h);

	public long ptr;

	private void welcome() {
		System.out.println("PSmile 1.1.0 by Bryan Chung");
	}

	/**
	 * return the version of the library.
	 * 
	 * @return String
	 */
	public static String version() {
		return VERSION;
	}

	public float getSmile(PImage _i) {
		PImage img = parent.createImage(w, h, ARGB);
		img.copy(_i, 0, 0, _i.width, _i.height, 0, 0, w, h);
		img.updatePixels();
		img.filter(GRAY);
		int total = w * h;
		float[] buffer = new float[total];
		for (int i = 0; i < total; i++) {
			buffer[i] = img.pixels[i] >> 16 & 0xFF;
		}
		float res = findSmile(buffer, w, h);
		return (res);
	}

	public static boolean isWindows() {
		String os = System.getProperty("os.name").toLowerCase();
		return (os.indexOf("win") >= 0);
	}

	public static boolean isMac() {
		String os = System.getProperty("os.name").toLowerCase();
		return (os.indexOf("mac") >= 0);
	}

	public static boolean is32Bit() {
		int arch = Integer.parseInt(System.getProperty("sun.arch.data.model"));
		return (arch == 32);
	}

	public static boolean is64Bit() {
		int arch = Integer.parseInt(System.getProperty("sun.arch.data.model"));
		return (arch == 64);
	}
}
