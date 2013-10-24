package org.kevx;

import java.io.File;
import java.io.IOException;
import java.io.StringReader;
import java.util.List;
import java.util.Map;
import java.util.Set;

import org.apache.commons.io.FileUtils;
import org.apache.commons.lang.StringUtils;
import org.apache.commons.lang.math.NumberUtils;
import org.wltea.analyzer.IKSegmentation;
import org.wltea.analyzer.Lexeme;

import com.google.common.collect.Maps;
import com.google.common.collect.Sets;

public class Bayes {
	
	private final Set<String> total = Sets.newHashSet();
	
	private final Map<String, Integer> good = Maps.newHashMap();

	private final Map<String, Integer> bad = Maps.newHashMap();
	
	private final Map<String, Double> probability = Maps.newHashMap();
	
	public static void main(String[] argv) {
		try {
			Bayes bayers = new Bayes();
			List<String> all = FileUtils.readLines(new File("D:\\tmp\\tmp1.txt"), "UTF-8");
			bayers.initData(all);
			bayers.learn();
			
			List<String> test = FileUtils.readLines(new File("D:\\tmp\\bayes_test.txt"), "UTF-8");
			for (String t : test) {
				System.out.println(t + "##:" + bayers.pSpam(t));
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public double pSpam(String title) {
		Set<String> words = Bayes.splitKeywords(title);
		if (words != null) {
			double a = 1;
			double b = 1;
			for (String w : words) {
				Double p = probability.get(w);
				if (p != null && p != 0 && p != 1) {
					a *= p;
					b *= (1 - p);
				}
			}
			return a / (a + b);
		}
		return 0;
	}
	
	private void initData(List<String> all) {
		for (String l : all) {
			String title = StringUtils.substringBefore(l, "\001");
			int status = NumberUtils.toInt(StringUtils.substringAfter(l, "\001"));
			Set<String> words = splitKeywords(title);
			for (String word : words) {
				total.add(word);
				if (status <= -1) {
					incrOrPut(bad, word);
				} else {
					incrOrPut(good, word);
				}
			}
		}
	}
	
	private void learn() {
		for (String w : total) {
			double pGood = good.get(w) == null ? 0.0d : (double)good.get(w);
			double pBad = bad.get(w) == null ? 0.0d : (double)bad.get(w);
			probability.put(w, (pBad)/(pGood + pBad));
			
		}
	}
	
	private static void incrOrPut(Map<String, Integer> map, String kw) {
		Integer i = map.get(kw);
		if (i != null) {
			i += 1;
		} else {
			i = 1;
		}
		map.put(kw, i);
	}
	
	public static Set<String> splitKeywords(String s) {
        Set<String> result = Sets.newHashSet();
        if (StringUtils.isNotBlank(s)) {
        	try {
                IKSegmentation ikSeg = new IKSegmentation(new StringReader(s), true);
                Lexeme l = null;
                while ((l = ikSeg.next()) != null) {
                    result.add(l.getLexemeText());
                }
            } catch (Exception e) {
            }
        }
        return result;
    }
}
